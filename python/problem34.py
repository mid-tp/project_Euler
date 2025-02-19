
#
# 145 is a curious number, as 1! + 4! + 5! = 1 + 24 + 120 = 145.
#
# Find the sum of all numbers which are equal to the sum of the factorial of their digits.
#
# Note: as 1! = 1 and 2! = 2 are not sums they are not included.

from time import time
start = time()
def factorial(n): #a simple factorial number
    num = 1
    while n > 1:
        num = num * n
        n -= 1
    return num

#first we have to figure out the upper bound
#
# upperbound = 9
# counter = 1
# nine_factorial = factorial(9)
# while counter*nine_factorial > upperbound:
#     upperbound*=10
#     upperbound+= 9
#     counter+= 1
# print(upperbound)



def factorial_digit_sum(num):
    old_num = num
    total = 0
    while num != 0:
        digit = num % 10
        total+= factorial(digit)
        if total > old_num:
            return 0
        num = num//10
    if total == old_num:
        return old_num
    else:
        return 0

#9999999
total2 = 0
for i in range(3,9999999+1):
    if factorial_digit_sum(i)==i:
        print(i)
        total2+=factorial_digit_sum(i)
print(total2)



end = time()
print(end-start)


