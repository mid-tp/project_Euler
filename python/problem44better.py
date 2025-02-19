#after some algebraic manipulation (easy google search)
#to check if a number is pentagonal or not is the following function
import math
from time import time
start = time()
def is_pantagonal(num):
    return (math.sqrt(24*num+1)+1)%6==0

def pentagonal_numbers(num):
    return (num*(3*num-1))//2

bound = 3000
min = 100000000
i = 2
while i < bound: # WORKS SLOWER ACTUALLY... EXPECTED TO WORK FASTER, works faster for higher bounds... (not relevant for this problem though)
    for j in range(1,i):
        Pi_Pjmin = pentagonal_numbers(i)-pentagonal_numbers(j)
        Pi_Pjadd = pentagonal_numbers(i)+pentagonal_numbers(j)
        if is_pantagonal(Pi_Pjadd) and is_pantagonal(Pi_Pjmin):
            if Pi_Pjmin < min:
                min = Pi_Pjmin
    i+=1
print(min)

end = time()
print("TIME:", end-start)