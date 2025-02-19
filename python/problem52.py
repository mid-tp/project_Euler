#
# It can be seen that the number, 125874, and its double, 251748, contain exactly the same digits, but in a different order.
#
# Find the smallest positive integer, x, such that 2x, 3x, 4x, 5x, and 6x, contain the same digits.

from time import time
import math
start = time()
def digit_gettter(num): #This function tells you how many digits of each digit a number contains
    digits = {}
    while num != 0:
        last_digit = num % 10
        if last_digit in digits.keys():
            digits[last_digit] += 1
        else:
            digits.update({last_digit:1})
        num = num // 10
    return digits

def same_digits(num,repeats):
    product,multiplier=0,2
    digits = digit_gettter(num)
    while multiplier <= repeats:
        num *= multiplier
        new_digits = digit_gettter(num)
        if digits == new_digits:
            multiplier += 1
        else:
            return False
    return True

def runner(repeats):
    multiplier = 1
    i = 1
    while True:
        if i // 10 ** int(math.log(i, 10)) > 1: #if it starts at anything higher than a 1, then times 6, you'll get 1 extra digit, hence they can never be equal
            i += 8 * multiplier
            multiplier *= 10
        if same_digits(i,repeats) == True:
            return i
        # print(i)
        i += 1

# print(runner(2))

#even easier, just get everything into a string, and order them.

upper = 5
i = 1034
count = 0
done = False
while not done:
    for multiplier in range(upper,1,-1):
        if sorted(str(multiplier*i)) != sorted(str(i)):
            break
    else: #little python thing here, this 'else' block only runs if the full range of multiplier is used, if we break out of the for loop, we will just go
        print(i)      # to the i += 1 part.
        done = True
    i += 1












end = time()


print(end-start)
