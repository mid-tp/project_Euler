#
#
# A googol (10100) is a massive number: one followed by one-hundred zeros; 100100 is almost unimaginably large: one followed by two-hundred zeros.
# Despite their size, the sum of the digits in each number is only 1.
#
# Considering natural numbers of the form, a^b, where a, b < 100, what is the maximum digital sum?

def digit_sum(num): #returns the sum of the digits of a number
    total = 0
    while num != 0:
        digit = num % 10
        total += digit
        num = num // 10
    return total


maximum = 0
for a in range(1,101):
    for b in range(1,101):
        digit_sum_of_a_power_b = digit_sum(a**b)
        if digit_sum_of_a_power_b > maximum:
            maximum=digit_sum_of_a_power_b

print(maximum)