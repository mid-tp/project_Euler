from time import *
import math
start = time()

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

def sum_prime(n):
    primes = list(n)
    sum=0
    for i in primes:
        sum+=i
    return sum
print(sum_prime(2000000))

end = time()
print("Time elapsed:", end-start)


