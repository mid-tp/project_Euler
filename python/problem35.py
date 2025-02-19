# The number, 197, is called a circular prime because all rotations of the digits: 197, 971, and 719, are themselves prime.
#
# There are thirteen such primes below 100: 2, 3, 5, 7, 11, 13, 17, 31, 37, 71, 73, 79, and 97.
#
# How many circular primes are there below one million?

#NOTE: ROTATIONS!!! not PERMUTATIONS
import math
import itertools
from time import time
begin = time()

def isprime(num):
    """
    Check if the number is prime or not.
    :param num: an integer
    :return: a boolean value, True if prime, False if not prime
    """
    for i in range(2, int(math.sqrt(num)) + 1):
        if (num % i) == 0:
            return False
    else:
        return True

def rotation(num):
    """
    Get all the ROTATIONS of a number in a list form.
    For example, the rotations of 197 are: " 197, 971, 719"
    :param num: an integer
    :return: a list with as elements, integers, the rotations of the input
    """
    order = math.floor(math.log10(num))
    rotationList = [num]
    for i in range(order):
        lastDigit = num % 10
        num -= lastDigit
        num /= 10
        num += lastDigit*(10**(order))
        rotationList.append(int(num))
    return rotationList

def contains5orEvenDigit(num):
    """
    @Requires the number to be greater or equal to 10.
    Checks if the number contains any of the following digits: 0,2,4,5,6,8
    :param num: an integer
    :return: a boolean value
    """
    digitSet = {0,2,4,5,6,8}
    while num != 0:
        digit = num % 10
        if digit in digitSet:
            return True
        num = num // 10
    return False




def cyclePrimes(upBound):
    cycleSet = {2,3,5,7}
    loopList = [i for i in range(11,upBound+1,2)]
    for num in loopList:
        if not contains5orEvenDigit(num) and isprime(num):
            primeRotations = rotation(num)
            for pRot in primeRotations:
                if not isprime(pRot):
                    break
            else:
                for pRot in primeRotations:
                    if pRot in loopList:
                        loopList.remove(pRot)
                    cycleSet.add(pRot)
    return len(cycleSet), cycleSet


print(cyclePrimes(10**6))



























print("TIME: ",time()-begin)















