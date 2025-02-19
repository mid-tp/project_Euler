def digit_sum(number):
    string = str(number)
    bigman = 0 #you don't know bruv
    for i in range(len(string)):
        bigman+=int(string[i])
    return bigman

print(digit_sum(2**1000))