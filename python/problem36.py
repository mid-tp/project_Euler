import math
def encode(x):
    alphabet = ["A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z"]
    if x < 10:
        return x
    else:
        return alphabet[x-10]

def to_k(n,k):
    number = 0
    i = 0
    while k**i<n:
        i += 1
    i -= 1
    while i >=0:
        a = math.floor(n/(k**i))
        encoded = encode(a)
        n = (n % (k**i))
        number += encoded * 10 ** i
        i -= 1
    return number

def palindrom_double_base(bound):
    total = 0
    for number in range(1,bound):
        str_num = str(number)
        if str_num == str_num[::-1]:
            base2 = to_k(number,2)
            str_base2 = str(base2)
            if str_base2 == str_base2[::-1]:
                total += number
    return total-2  #for some reason, 2 in base 2 is also 2, which is wrong, so we subtract that.

print(palindrom_double_base(1000000))

