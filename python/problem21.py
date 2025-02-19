import math
from math import *

# (n) be defined as the sum of proper divisors of n (numbers less than n which divide evenly into n).
# If d(a) = b and d(b) = a, where a ≠ b, then a and b are an amicable pair and each of a and b are called amicable numbers.
#
# For example, the proper divisors of 220 are 1, 2, 4, 5, 10, 11, 20, 22, 44, 55 and 110; therefore d(220) = 284.
# The proper divisors of 284 are 1, 2, 4, 71 and 142; so d(284) = 220.
#
# Evaluate the sum of all the amicable numbers under 10000.

def divisor_sum(num): #O(sqrt(n)) algorithm
    sum,i = 0,1
    while i <= math.sqrt(num):
        if (num % i)==0:
            if num / i == i:
                sum+= num / i
            else:
                sum+= i
                sum += num/i
        i+=1
    return int(sum)-num #PROPER divisor, so the number itslef should not be considered.



def amicable_numbers(num):
    amice = {}
    totalsum = 0
    for i in range(2,num+1):
        tempsum = divisor_sum(i)
        if tempsum >1:
            if tempsum in amice.keys():
                amice_tuple = amice.items()
                for item in amice_tuple:
                    if item[0] == tempsum and item[1] == i:
                        totalsum += item[0]+item[1]
            if i != divisor_sum(i):
                gast = {i:tempsum}
                amice.update(gast)
    return totalsum,amice

print(amicable_numbers(10000))









