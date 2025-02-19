# A perfect number is a number for which the sum of its proper divisors is exactly equal to the number.
# For example, the sum of the proper divisors of 28 would be 1 + 2 + 4 + 7 + 14 = 28, which means that 28 is a perfect number.
#
# A number n is called deficient if the sum of its proper divisors is less than n and it is called abundant if this sum exceeds n.
#
# As 12 is the smallest abundant number, 1 + 2 + 3 + 4 + 6 = 16, the smallest number that can be written as the
# sum of two abundant numbers is 24. By mathematical analysis, it can be shown that all integers greater than 28123 can be written as the sum
# of two abundant numbers. However, this upper limit cannot be reduced any further by analysis even though it is known that the greatest number
# that cannot be expressed as the sum of two abundant numbers is less than this limit.
#
# Find the sum of all the positive integers which cannot be written as the sum of two abundant numbers.
import math
from time import time
begin = time()
def sumOfDivisors(num):
    """
    A method that checks if a number is abundant or not.
    :param num: the number to check
    :return: a boolean value. True if abundant, False if not.
    """
    sum = 1
    for i in range(2,int(math.sqrt(num))+1):
        if (num % i) == 0:
            if math.sqrt(num) == i:
                sum += i
            else:
                sum += i
                sum += num/i
    return int(sum)

def isAbundantSum(set,num):
    for i in set:
        if (num-i) in set:
            return True
    return False


#We know initialised the list. Now we have to check if a number is a sum of 2 elements in the list.
#We'll do this is follows. We loop over the list, subtract the element from the list from the number that we want to check.
#We obtain the difference, if the difference is in the keySet of our HashMap (constant lookup time :)) the number is a sum of 2 abundant numbers.
#If we found such a pair, we'll break. If not, we'll keep looping over the abundantList untill we find a pair or not.
abundantList = []
abundantSet = set()
noSum = 0
for i in range(1,28123):
    sum = sumOfDivisors(i)
    if sum > i:
        abundantList.append(i)
        abundantSet.add(i)
    if not isAbundantSum(abundantSet,i):
        noSum+=i

print("No sum  ", noSum)
print("TIME: ",time()-begin)
