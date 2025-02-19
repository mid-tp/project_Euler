# Euler discovered the remarkable quadratic formula:
#
# n2+n+41
#
# It turns out that the formula will produce 40 primes for the consecutive integer values 0≤n≤39
# . However, when n=40,402+40+41=40(40+1)+41 is divisible by 41, and certainly when n=41,412+41+41
#
# is clearly divisible by 41.
#
# The incredible formula n2−79n+1601
# was discovered, which produces 80 primes for the consecutive values 0≤n≤79
#
# . The product of the coefficients, −79 and 1601, is −126479.
#
# Considering quadratics of the form:
#
#     n2+an+b
#
# , where |a|<1000 and |b|≤1000
#
# where |n|
# is the modulus/absolute value of n
# e.g. |11|=11 and |−4|=4
#
# Find the product of the coefficients, a
# and b, for the quadratic expression that produces the maximum number of primes for consecutive values of n, starting with n=0.
import math


def isprime(num1):
    for i in range(2,int(math.sqrt(num1))+1):
        if (num1 % i) == 0:
            break
    else:
        return num1

def primelist(num): #finally made an efficient prime lister less than N
    primes = []
    for j in range(2,num):
        if isprime(j)==j:
            primes.append(j)
    return primes

def quadratic_primes(a_bound,b_bound):
    a_param, b_param, product, max_length = 0,0,0,0
    primes = primelist(b_bound+1)
    totallist = primes[::]
    for prime in primes:
        totallist.append(-prime)
    for a in range(-a_bound+1,a_bound):
        for b in primes:
            n = 0
            length = 0
            while n**2+a*n+b > 0 and isprime(n**2+a*n+b)== n**2+a*n+b:
                n+=1
                length+=1
                if length > max_length:
                    max_length = length
                    a_param, b_param = a, b
                    product = a*b
    return a_param, b_param, product

print(quadratic_primes(1000,1000))







