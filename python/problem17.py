# If the numbers 1 to 5 are written out in words: one, two, three, four, five, then there are 3 + 3 + 5 + 4 + 4 = 19 letters used in total.
#
# If all the numbers from 1 to 1000 (one thousand) inclusive were written out in words, how many letters would be used?
#
# NOTE: Do not count spaces or hyphens. For example, 342 (three hundred and forty-two) contains 23 letters
# and 115 (one hundred and fifteen) contains 20 letters. The use of "and" when writing out numbers is in compliance with British usage.

singles = ["one","two","three","four","five","six","seven","eight","nine"]
tens = ["eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","nineteen"]

doubles = ["twenty","thirty","forty","fifty","sixty","seventy","eighty","ninety"]

#--------------------Part less than 100---------------------------
count = 0
singleCount = 0
for i in singles:
    print(i)
    singleCount+=len(i)
print("\n",singleCount,"\n")

tenCount = 0
for i in tens:
    print(i)
    tenCount += len(i)
print("\n",tenCount,"\n")

doublesCount = 0
doublesCount+=len("ten")
print("ten")
for i in doubles:
    print(i)
    doublesCount += len(i)
print("\n",doublesCount,"\n")

doubleList = []
mixCount = 0
for i in doubles:
    for j in singles:
        doubleList.append(i+j)
        print(i+" "+j)
        mixCount+=len(i)+len(j)
print("\n",mixCount,"\n")

hundredCount = singleCount+tenCount+doublesCount+mixCount
#---------------------------------------------------------------------------------

print(hundredCount)
total = 0
lenHun = len("hundred")
lenAnd = len("and")
doubles.append("ten")
totalList = singles+tens+doubleList+doubles
for i in singles:
    #TODO: tenners
    for ten in totalList:
        print("\n",i+ " hundred and "+ten,len(i)+lenHun+lenAnd+len(ten))
        total += len(i)+lenHun+lenAnd+len(ten)

for i in singles:
    print("\n", i + "hundred")
    total += len(i) + lenHun


total += len("one")+len("thousand")
print(total+hundredCount)

