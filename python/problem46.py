from time import *
start = time()
import math
# It was proposed by Christian Goldbach that every odd composite number can be written as the sum of a prime and twice a square.
#
# 9 = 7 + 2×1^2
# 15 = 7 + 2×2^2
# 21 = 3 + 2×3^2
# 25 = 7 + 2×3^2
# 27 = 19 + 2×2^2
# 33 = 31 + 2×1^2
#
# It turns out that the conjecture was false.
#
# What is the smallest odd composite that cannot be written as the sum of a prime and twice a square?

def isprime(num1):
    for i in range(2,int(math.sqrt(num1))+1):
        if (num1 % i) == 0:
            break
    else:
        return num1

def prime_oddcomposite_list(num): #finally made an efficient prime lister less than N
    primelist,oddcomposite_list= [],[]
    for j in range(2,num):
        if isprime(j)==j:
            primelist.append(j)
        else:
            if (j%2)==0:
                pass
            else:
                oddcomposite_list.append(j)

    return primelist,oddcomposite_list

def int_checker(num):
    str_num = str(num)
    if str_num[-1] == "0":
        return num
    else:
        return -1

def golbach_conjecture_false(num):
    count = 0
    prime_list,odd_composite_list = prime_oddcomposite_list(num)
    for odd_c in odd_composite_list:
        if odd_c > 1:
            for prime in prime_list:
                if prime > odd_c:
                    break
                dif = math.sqrt((odd_c-prime)/2)
                if int_checker(dif) == dif:
                    if odd_c == odd_composite_list[count]:
                        count += 1
                        break
                    else:
                        return odd_composite_list[count] #this is the number that was skipped, so the number that could not have been made out of prime +square.

print(golbach_conjecture_false(6000))
#easier if you only make the next number, and then check, and then make the next number, now most time is spent in making the list.
end = time()
print("Time", end-start)