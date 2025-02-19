#
# The 5-digit number, 16807=7^5, is also a fifth power. Similarly, the 9-digit number, 134217728=8^9, is a ninth power.
#
# How many n-digit positive integers exist which are also an nth power?


count = 0
checker = True
checker_count = 0
for num in range(1,100000):
    # if checker is False:
    #     break
    for power in range(1,50):
        if checker_count > 1:
            checker = False
        str_num = str(num**power)
        if len(str_num) > power:
            checker_count+= 100:
            break
        if len(str_num) == power:
            count += 1
            checker = True
            checker_count = 0

print(count)

