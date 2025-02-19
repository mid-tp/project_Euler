import math
from time import time
start = time()

def triplets_finder(n):
    for i in range(2,n): #a
        for j in range(i,n): # b   a<b<c, so if j < i then we break
             c = i**2+j**2
             sqrt_c = math.sqrt(c)
             if i + j + sqrt_c == 1000:
                return i*j*sqrt_c





end = time()
print("Time elapsed:", end-start)
