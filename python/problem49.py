#
# The arithmetic sequence, 1487, 4817, 8147, in which each of the terms increases by 3330, is unusual in two ways: (i) each of the three terms are prime, and,
# (ii) each of the 4-digit numbers are permutations of one another.
#
# There are no arithmetic sequences made up of three 1-, 2-, or 3-digit primes, exhibiting this property, but there is one other 4-digit increasing sequence.
#
# What 12-digit number do you form by concatenating the three terms in this sequence?

import itertools
import math
from time import time
t = time()
def isprime(num1):
    for i in range(2,int(math.sqrt(num1))+1):
        if (num1 % i) == 0:
            return 0
    else:
        return num1

def primelist(num):
    primelist= []
    for j in range(2,num):
        if isprime(j)==j:
            primelist.append(j)
    return primelist


def fromNumberToList(num):
    """
    Get a list of integers representing the digits of an integer.
    So the number 1254 --> [1,2,5,4]
    :param num: an integer
    :return: a list with as elements the digits of the input
    """
    numList = []
    while num != 0:
        toAdd = num % 10
        numList.insert(0,toAdd)
        num = num // 10
    return numList

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

def equalDifference(list):
    """
    A method that checks if there are three numbers of equal distance in this list.
    We do have to assume that the set is sorted.
    Requires the list to have at least 3 elements.
    :param list: a sorted list of numbers
    :return: the integer 0 if no such numbers exist. If these 3 numbers do exist, we will return the three numbers in a tuple
    """
    if len(list)<3:
        return 0

    for beginIndex in range(len(list)-1):
        for loopIndex in range(beginIndex+1,len(list)):
            # print("Begin ",beginIndex," loop ",loopIndex)
            begin = list[beginIndex]
            loop = list[loopIndex]
            diff = loop-begin
            if (loop+diff) in list:
                return begin,loop,loop+diff
    return 0



# print(list(itertools.permutations([1, 4,7,8])))

#We know that it's an increasing sequance
def run(upperLimit):
    #We will make a prime set only once so that we have constant look up time if we want to check if a number is prime or not. Which we will have to do a lot
    #So this will speed things up a lot.
    primeSet = set()
    for i in range(1000, upperLimit):
        if isprime(i) == i:
            primeSet.add(i)

    count = 0 #we know that there are only 2 sets of numbers with this property, so we'll stop when we found 2.
    loopList = [i for i in range(1000,upperLimit)]
    #loopList
    for num in loopList:
        if num in primeSet: #first check if the number itself is prime. If so, create all the permutations.
            permList = list(itertools.permutations(fromNumberToList(num)))
            for i in range(len(permList)):
                perm = permList[0]
                if isinstance(perm, int): #once we hit the first appended integer, we break. This is because we have looped over all the tuples
                    break
                permList.pop(0)
                permNum = fromTupleToNumber(perm)
                if permNum in primeSet and permNum >=1000:
                    if permNum not in permList:
                        permList.append(permNum)
                if permNum in loopList:
                    loopList.remove(permNum)
            permList.sort()
            answer = equalDifference(permList)
            if answer != 0:
                print("Answer ",answer," Difference: ", answer[1]-answer[0])
                count += 1
                if count == 2: #we just stop when we found 2 such pairs of numbers
                    return None

run(10000)
print("Time: ",time()-t)

#No other numbers in range(9000000) have this property
#Result:

# Answer  (1487, 4817, 8147)  Difference:  3330
# Answer  (2969, 6299, 9629)  Difference:  3330
# Time:  310.1418993473053



