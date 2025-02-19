# An irrational decimal fraction is created by concatenating the positive integers:
#
# 0.123456789101112131415161718192021...
#
# It can be seen that the 12th digit of the fractional part is 1.
#
# If dn represents the nth digit of the fractional part, find the value of the following expression.
#
# d1 × d10 × d100 × d1000 × d10000 × d100000 × d1000000
begin = str(0.)
for i in range(1,1000000+1):
    to_add = str(i)
    begin += to_add
product = int(begin[2+1])*int(begin[2+10])*int(begin[2+100])*int(begin[2+1000])*int(begin[2+10000])*int(begin[2+100000])*int(begin[2+1000000])
print(product)

