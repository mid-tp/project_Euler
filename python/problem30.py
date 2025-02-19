from time import time


# Surprisingly there are only three numbers that can be written as the sum of fourth powers of their digits:
#
#     1634 = 14 + 64 + 34 + 44
#     8208 = 84 + 24 + 04 + 84
#     9474 = 94 + 44 + 74 + 44
#
# As 1 = 14 is not a sum it is not included.
#
# The sum of these numbers is 1634 + 8208 + 9474 = 19316.
#
# Find the sum of all the numbers that can be written as the sum of fifth powers of their digits.

start = time()

def digit_powers(power):
    list_power = []
    for number in range(2,3000000): #just pick some large number for an upperbound
        string_number = str(number)
        temp = 0
        length_count = 0
        for part in string_number:
            temp += int(part)**power
            length_count+=1
            if temp > number:
                break
            if temp == number and length_count == len(string_number):
                list_power.append(number)
    total = 0
    for i in list_power:
        total += i
    return list_power, total

print(digit_powers(5))


































end = time()

print("Time", end-start)