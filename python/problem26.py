from decimal import *
import math
from time import *
start = time()
getcontext().prec = 500 # set the number of decimal places to 28
# A unit fraction contains 1 in the numerator. The decimal representation of the unit fractions with denominators 2 to 10 are given:
#
#     1/2	= 	0.5
#     1/3	= 	0.(3)
#     1/4	= 	0.25
#     1/5	= 	0.2
#     1/6	= 	0.1(6)
#     1/7	= 	0.(142857)
#     1/8	= 	0.125
#     1/9	= 	0.(1)
#     1/10	= 	0.1
#
# Where 0.1(6) means 0.166666..., and has a 1-digit recurring cycle. It can be seen that 1/7 has a 6-digit recurring cycle.
#
# Find the value of d < 1000 for which 1/d contains the longest recurring cycle in its decimal fraction part.


#TODO: how to detect a cycle?
# put all numbers in a string, loop over the string


def construct_cycle_length(bound):
    max_length, number_of_cycle = 0,0
    for number in range(2,bound+1):
        breaker = True
        remainders_set = set()
        value = 1
        while breaker is True:
            remainder = value % number
            if remainder in remainders_set or remainder == 0:
                breaker = False
                if len(remainders_set) > max_length:
                    max_length = len(remainders_set)
                    number_of_cycle = number
            else:
                 remainders_set.add(remainder)
                 value = 10*remainder
    return max_length,number_of_cycle

print(construct_cycle_length(1000))


#here we only care about the remainder of the next decimal number,
#that is why we multiply by 10, to get to the next decimal place.
# if we meet a remainder for a second time, it means we hit a cycle, look at YT steenbergh https://www.youtube.com/watch?v=Pf3eYSckAGY, idea.

















end = time()
print("Time:",end-start)