# The number, 1406357289, is a 0 to 9 pandigital number because it is made up of each of the
# digits 0 to 9 in some order, but it also has a rather interesting sub-string divisibility property.
#
# Let d1 be the 1st digit, d2 be the 2nd digit, and so on. In this way, we note the following:
#
#     d2d3d4=406 is divisible by 2
#     d3d4d5=063 is divisible by 3
#     d4d5d6=635 is divisible by 5
#     d5d6d7=357 is divisible by 7
#     d6d7d8=572 is divisible by 11
#     d7d8d9=728 is divisible by 13
#     d8d9d10=289 is divisible by 17
#
# Find the sum of all 0 to 9 pandigital numbers with this property.

from time import time
import itertools

begin = time()

def fromTupleToNumber(tuple):
    """
    A method that converts a tuple to a integer number
    :param tuple: the tuple with integers as elements
    :return: an integer
    """
    num = 0
    index = len(tuple)-1
    power = 0
    while index != -1:
        num += tuple[index]*10**(power)
        index -= 1
        power += 1
    return num


def isPandigital(num):
    """
    Checks if a number is pandigital,for an n-digit number.
     Meaning, does it contain all the digits 1 up to n exactly once.
     This method is only valid for numbers with less than 10 digits
     Only takes values that have 10 digits.
    :param num: an integer
    :return: a boolean value. True if the number is pandigital, False if not.
    """
    if num < 10**9 or num > 10**10:
        return False
    pan_set = {0,1,2,3,4,5,6,7,8,9}
    check_set = set()
    i = 1
    while num > 0:
        digit = num % 10
        check_set.add(digit)
        i+=1
        num = num//10
    if check_set == pan_set:
        return True
    else:
        return False

def subString(begin,end,num):
    """
    Get the 'sub string' value of an integer.
    The beginning and end determine how to 'slice' the integer.
    Indices start at 0. The end is up to and including.
    Deletes any preceding zeroes.
    :param begin: the begin index of where we want we slice
    :param end: the end index of where to slice
    :param num: the number of which we want the substring
    :return: an integer that is a 'substring' of the input
    """
    strNum = str(num)
    try:
        subNum = strNum[begin:end+1]
        while subNum[0] == 0:
            subNum = subNum[1:]
        return int(subNum)
    except:
        print("Num ",num)
        print(subNum,begin,end)


primeList = [2,3,5,7,11,13,17]
# for i in range(len(primeList)):
#     subNum = subString(1 + i, 3 + i, 1406357289)
#     check = True
#     if (subNum % primeList[i]) != 0:
#         check = False
#         break
# if check:
#     print("yeey")



sum = 0
pandigitalList = list(itertools.permutations([1,2,3,4,5,6,7,8,9,0]))
print(len(pandigitalList))
for tuple in pandigitalList:
    print(tuple)
    for i in range(len(primeList)):
        number = fromTupleToNumber(tuple)
        subNum = subString(1 + i, 3 + i, number)
        check = True
        if (subNum % primeList[i]) != 0:
            check = False
            break
    if check:
        sum += number



print(sum)
print("TIME:", time()-begin)

print(10**10-10**9)