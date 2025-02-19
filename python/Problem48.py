def powers(n):
    sum = 0
    i = 1
    list = []
    while i < n+1:
        sum += i**i
        i += 1
    string_sum = str(sum)
    return string_sum[-10:]
print(powers(1000))