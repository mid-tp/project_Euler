
# The number 3797 has an interesting property. Being prime itself, it is possible to continuously remove digits from left to right, and 4
# remain prime at each stage: 3797, 797, 97, and 7. Similarly we can work from right to left: 3797, 379, 37, and 3.
#
# Find the sum of the only eleven primes that are both truncatable from left to right and right to left.
#
# NOTE: 2, 3, 5, and 7 are not considered to be truncatable primes.
import math
from time import time
begin = time()
def isprime(num1):
    if num1 == 1:
        return 0
    for i in range(2,int(math.sqrt(num1))+1):
        if (num1 % i) == 0:
            break
    else:
        return num1

def primelist(num):
    primelist= []
    for j in range(10,num):
        if isprime(j)==j:
            primelist.append(j)
    return primelist


def remove_last_digit(num):
    num = num //10
    return num

def remove_first_digit(num):
    str_num = str(num)
    if len(str_num) == 1:
        return 0
    str_num = str_num[1:]
    int_num = int(str_num)
    return int_num
list_of_primes = primelist(800000)

counter = 0
total =0
done = False
while not done:
    for prime in list_of_primes:
        if done is True:
            break
        dum1,dum2 = prime,prime
        while dum1 != 0:
            dum1 = remove_last_digit(dum1)
            if isprime(dum1) == dum1:
                if dum1 == 0:
                    while dum2 != 0:
                        dum2 = remove_first_digit(dum2)
                        if isprime(dum2) == dum2:
                            if dum2 == 0:
                                total += prime
                                counter += 1
                                print("Counter",counter,"Total",total,"Prime Number",prime)
                                if counter > 10:
                                    done = True
                        else:
                            break
            else:
                break

end = time()
print('Time:',end-begin)