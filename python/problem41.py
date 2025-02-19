#
# We shall say that an n-digit number is pandigital if it makes use of all the digits 1 to n exactly once.
# For example, 2143 is a 4-digit pandigital and is also prime.
#
# What is the largest n-digit pandigital prime that exists?

import math
from time import time
start = time()
def isprime(num1):
    for i in range(2,int(math.sqrt(num1))+1):
        if (num1 % i) == 0:
            break
    else:
        return num1
def ispandigital(num):
    pan_set = set()
    check_set = set()
    i = 1
    while num > 0:
        digit = num % 10
        check_set.add(digit)
        pan_set.add(i)
        i+=1
        num = num//10
    if check_set == pan_set:
        return True
    else:
        return False

i = 8000000
max_pan_prime = 0
# while i > 4765213:
#     if isprime(i) == i:
#         if ispandigital(i) is True:
#             if i > max_pan_prime:
#                 max_pan_prime = i
#     i -= 1
# print(max_pan_prime)


#can be sped up by noting that "    A number is divisible by 3 if sum of its digits is divisible by 3. " So you only check the 7 digit numbers...

for i in range(999999,10000000):
    if isprime(i) == i:
        if ispandigital(i) is True:
            if i > max_pan_prime:
                max_pan_prime = i

print(max_pan_prime)

end = time()
print(end-start)
