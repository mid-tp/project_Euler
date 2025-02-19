from time import time
start = time()
#
# A number chain is created by continuously adding the square of the digits in a number to form a new number until it has been seen before.
#
# For example,
#
# 44 → 32 → 13 → 10 → 1 → 1
# 85 → 89 → 145 → 42 → 20 → 4 → 16 → 37 → 58 → 89
#
# Therefore any chain that arrives at 1 or 89 will become stuck in an endless loop.
# What is most amazing is that EVERY starting number will eventually arrive at 1 or 89.
#
# How many starting numbers below ten million will arrive at 89?

def digit_square(num):
    new_num = 0
    str_num = str(num)
    for digit in str_num:
        new_num += int(digit)**2
    return new_num

def square_digit_chain(lower,upper):
    end_at_89 = set()
    end_at_1 = set()
    for i in range(lower,upper+1):
        temp_list_89 = []
        temp_list_1 = []
        next_num = i
        while next_num != 1: #I check way too many things, but it works, yey
            if next_num == 89:
                if len(temp_list_89) == 0:
                    end_at_89.add(i)
                    break
                else:
                    for number in temp_list_89:
                        end_at_89.add(number)
                    break
            if next_num in end_at_89:
                if len(temp_list_89) == 0:
                    end_at_89.add(i)
                    break
                else:
                    for number in temp_list_89:
                        end_at_89.add(number)
                    break
            if next_num in end_at_1:
                for number in temp_list_1:
                    end_at_1.add(number)
                break
            else:
                temp_list_89.append(next_num)
                temp_list_1.append(next_num)
                next_num = digit_square(next_num)
        if next_num == 1:
            for number in temp_list_1:
                end_at_1.add(number)
    return len(end_at_89) #speed this up by using the fact that 15, 150, 51, 15000, all give the same result.


print(square_digit_chain(1,10000000))

end = time()

print("Time:", end-start, "seconds")


