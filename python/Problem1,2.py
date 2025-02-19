from time import time
import math
start = time()
sum = 0
for i in range(0,1000):
    if i % 3 == 0 or i % 5 == 0:
        sum += i


def fib(n):
    fib1 = 1
    fib2 = 2
    total = 0
    fib_list = [1,2]
    sum = 0
    while total < n:
        total = fib1+fib2
        fib1, fib2 = fib2, total
        fib_list.append(total)
    for i in fib_list:
        if i % 2 ==0 and i < n:
            sum += i
    return sum

def square_diff(n):
    sum_of_squares = 0
    square_of_sum = 0
    i = 0
    j = 0
    while i < n+1:
        sum_of_squares += i**2
        i += 1
    while j < n+1:
        square_of_sum += j
        j += 1
    return square_of_sum**2-sum_of_squares

def prime_checker(num1):
    for j in range(2,math.ceil(num1/2)):
        if (num1 % j) == 0:
            break
    else:
        return num1

def large_prime_number(n):
    prime_list = []
    num1 = 2 #this is the number we check if it is prime
    max = 2
    while len(prime_list) < n:
        #check if the nmbr is prime, if so add it to the list, and increase by one
        # if not, just increase the nmbr by one
        for i in range(num1,num1+1):
            if num1 % i ==0 and prime_checker(i) == i:
                prime_list.append(i)
                num1 += 1
            else:
                num1 += 1
    return prime_list[-1], prime_list

print(large_prime_number(10002))



end = time()
print("Time elapsed:", end-start)
