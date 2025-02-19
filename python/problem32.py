# We shall say that an n-digit number is pandigital if it makes use of all the digits 1 to n exactly once;
# for example, the 5-digit number, 15234, is 1 through 5 pandigital.
#
# The product 7254 is unusual, as the identity, 39 × 186 = 7254, containing multiplicand, multiplier, and product is 1 through 9 pandigital.
#
# Find the sum of all products whose multiplicand/multiplier/product identity can be written as a 1 through 9 pandigital.
# HINT: Some products can be obtained in more than one way so be sure to only include it once in your sum.
import math
from time import time
begin = time()
def digit_gettter(num):
    """
    This method tells you how many times a digit is present in a number.
    The output is in a dictionary form.
    :param num: an integer value
    :return: a dictionary with as keys the digits, as value how many times they are present.
    """
    digits = {}
    while num != 0:
        last_digit = num % 10
        if last_digit in digits.keys():
            digits[last_digit] += 1
        else:
            digits.update({last_digit:1})
        num = num // 10
    return digits

def shareDigit(num1,num2):
    """
    Checks if two integer numbers have a digit in common.
    We will restrict ourselves to integers with 2 digits only.
    Also, we assume that num1 is always stricly smaller than num2.
    :param num1: integer
    :param num2: integer
    :return: a boolean value. True if they do share a digit, False if the input inegers do not have a digit in common.
    """
    digitNum1 = digit_gettter(num1)
    digitNum2 = digit_gettter(num2)
    for digit in digitNum1.keys():
        if digit in digitNum2.keys():
            return True
    return False

print(shareDigit(123334,11100000000))


def isNdigital(num):
    """
    Checks if a number is n-digital,for an n-digit number.
     Meaning, does it contain all the digits 1 up to n exactly once.
     This method is only valid for numbers with less than 10 digits
    :param num: an integer
    :return: a boolean value. True if the number is pandigital, False if not.
    """
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

#brute force let's go
# We can restrict the for loop by a lot (only from 10 up to 100, and 100 up to 500 or smth
panSet = set()
panSum = 0
for i in range(1,100):
    for j in range(100,10000):#no explanation for the bounds. Just mess around with them a bit. If we take 1 to 100 and 100 to 10000 we're safe for sure.
        result = i*j
        panDigit = str(i)+str(j)+str(result)
        intPan = int(panDigit)
        if len(panDigit)>9:
            break
        elif len(panDigit)==9:
            if isNdigital(intPan):
                if result not in panSet:
                    panSum += result
                    panSet.add(result)

print(7254 in panSet)
print(panSum,panSet)

print("TIME: ",time()-begin)