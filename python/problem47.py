#
# The first two consecutive numbers to have two distinct prime factors are:
#
# 14 = 2 × 7
# 15 = 3 × 5
#
# The first three consecutive numbers to have three distinct prime factors are:
#
# 644 = 2² × 7 × 23
# 645 = 3 × 5 × 43
# 646 = 2 × 17 × 19.
#
# Find the first four consecutive integers to have four distinct prime factors each. What is the first of these numbers?

import math
from time import time
start = time()

def isprime(num1):
    for i in range(2,int(math.sqrt(num1))+1):
        if (num1 % i) == 0:
            break
    else:
        return num1

def primelist(num):
    primelist= []
    for j in range(2,num):
        if isprime(j)==j:
            primelist.append(j)
    return primelist
LIST = primelist(700) #here we only generate the list once, which speeds up the process, know we do have to guess what the highest prime factor is gonna be..
def prime_factor(num,num_of_factors):
    unique_factors = {}
    for i in LIST:
        if num == 1:
            break
        while (num%i)==0 and isprime(i)==i:
            if i in unique_factors.keys():
                unique_factors[i] += 1
            else:
                unique_factors.update({i:1})
            num/=i
    if len(unique_factors) == num_of_factors:
        return unique_factors
    else:
        return {1:1}

def similar_keys(dict1,dict2): #if two numbers have different factors, return True, if they have a factor in common, return False
    for i in dict1.keys():    # we do use here that the dictionaries are ordered from small to large numbers, keys can be the same, the value cant
        for j in dict2.keys():
            if i == j:
                if dict1[i] == dict2[j]:
                    return False
            if i < j:
                break
    return True

def distinct_factor(num_consecutive): # to speed up, make a list of primes once,
    i = 1
    done = False
    while not done:
        if isprime(i)==i or isprime(i+1)==i+1 or isprime(i+2)==i+2:# or isprime(i+3)==i+3:
            i+=1
        else:
            factor1 = prime_factor(i,num_consecutive)
            factor2 = prime_factor(i+1,num_consecutive)
            if len(factor1)==num_consecutive and  len(factor2)==num_consecutive and similar_keys(factor1,factor2) is True:
                # return i,i+1 #run with input 2
                factor3 = prime_factor(i+2,num_consecutive)
                print(i)
                if  len(factor3)==num_consecutive and similar_keys(factor1,factor3) is True and similar_keys(factor2,factor3) is True:
                    # return i,i+1,i+2, #run with input 3
                    factor4 = prime_factor(i+3,num_consecutive)
                    print(i,i+1,i+2)
                    if len(factor4)==num_consecutive and similar_keys(factor1,factor4) is True and similar_keys(factor2,factor4)is True and  similar_keys(factor3 ,factor4) is True:
                        return i,i+1,i+2,i+3
            i+=1

print(distinct_factor(4))

end = time()
print(end-start)

