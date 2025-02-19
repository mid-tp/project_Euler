from time import *
import math
start = time()

# The prime 41, can be written as the sum of six consecutive primes:
# 41 = 2 + 3 + 5 + 7 + 11 + 13
#
# This is the longest sum of consecutive primes that adds to a prime below one-hundred.
#
# The longest sum of consecutive primes below one-thousand that adds to a prime, contains 21 terms, and is equal to 953.
#
# Which prime, below one-million, can be written as the sum of the most consecutive primes?

def isprime(num1):
    for i in range(2,int(math.sqrt(num1))+1): #pretty damn fast, doesnt work though, it says that 961 is prime..
        if (num1 % i) == 0:
            break
    else:
        return num1
# print(isprime(961)==961)

def list(num): #finally made an efficient prime lister less than N
    primelist=[]
    for j in range(2,num):
        if isprime(j)==j:
            primelist.append(j)
    return primelist

def sum_list(primes,a,b,n):
    sum=0
    for i in range(a, b):  # takes sum untill b
        sum += primes[i]
        if sum > n:
            break
    return sum
#idea: Once you find a larger sequence, you sum them, and check if it is prime, if it is and it consists of more primes, you found a new maxprime
def sum(n):
    primes = list(n)
    maxcount=0
    maxsum=0
    length = int(len(primes))
    for a in range(len(primes)+1):
        for b in range(a+1,len(primes)+1): #considers all sequences
            if b-a>maxcount: #makes sure only sequences larger than the larger sequence are considered.
                sum = sum_list(primes,a,b,n)
                if sum>n:
                    print(sum)
                    break

                if isprime(sum)==sum:
                    maxcount=b-a
                    maxsum=sum
                    print(maxsum)
    return maxsum,maxcount
print(sum(1000000))
end = time()
print("Time elapsed:", end-start)
