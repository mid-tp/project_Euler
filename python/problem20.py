def fact(n):
    num = 1
    while n > 1:
        num = num * n
        n -= 1
    return str(num)
def digit_sum(n):
    a = fact(n)
    sum = 0
    for i in range(0,len(a)):
        sum += int(a[i])
    return sum, a
print(digit_sum(100))
