from time import *
import math
start = time()


# The following iterative sequence is defined for the set of positive integers:
#
# n → n/2 (n is even)
# n → 3n + 1 (n is odd)
#
# Using the rule above and starting with 13, we generate the following sequence:
# 13 → 40 → 20 → 10 → 5 → 16 → 8 → 4 → 2 → 1
#
# It can be seen that this sequence (starting at 13 and finishing at 1) contains 10 terms. Although it has not been proved yet (Collatz Problem), it is thought that all starting numbers finish at 1.
#
# Which starting number, under one million, produces the longest chain?
#
# NOTE: Once the chain starts the terms are allowed to go above one million.

#Todo: use dictionary to solve this problem, once we know how long it takes to get back to 1 from a certain number, store it in a dict
# so that we don't have to calculate the length of every sequence all over again.


# class counting(object):
#     def __init__(self,counter,dict):
#         self._counter = counter
#         self._dict = dict
#
#
#
#     def collatz(self,n):
#         while n !=1:
#             if (n%2)==0:
#                 n=n/2
#                 self._counter+=1
#             else:
#                 n = n*3+1
#                 self._counter+=1


def collatz(num):
    realnum=num
    count = 1
    diction = {}
    while num!=1:
        if (num%2)==0:
            num/=2
            count+=1
        else:
            num = num*3+1
            count+=1
    diction = {realnum:count}
    return count

def large_collatz(up_bound):
    large_count=0
    l = []
    for i in range(1,up_bound+1):
        count1 = collatz(i)
        l.append(count1)
        if count1>large_count:
            large_count=count1
            realI = i
    return realI,large_count

print(large_collatz(1000000))


end = time()
print("Time elapsed:", end-start)
