
#
# If p is the perimeter of a right angle triangle with integral length sides, {a,b,c}, there are exactly three solutions for p = 120.
#
# {20,48,52}, {24,45,51}, {30,40,50}
#
# For which value of p ≤ 1000, is the number of solutions maximised?
from time import time
import math
start = time()
#just create all pythagorean triplets, and create a sorted dictionary with {perimeter:number of solutions}


def pythagorean_triplets():
    triplet_perimeter = {} #key = perimeter, value = number of right hand triangle solutions
    for a in range(3,1000): #let them run up to 1000, if one side of a triangle is already 1000, the whole perimeter will be longer for sure
        for b in range(a+1,1000):
            c = math.sqrt(a**2+b**2)
            if a**2+b**2== c**2:
                if a+b+c>1000:
                    break
                else:
                    if a+b+c in triplet_perimeter.keys():
                        triplet_perimeter[a+b+c] += 1
                    else:
                        triplet_perimeter.update({a+b+c:1})
    return sorted(triplet_perimeter.items(),key=lambda t: t[1]) #last element is the one we are looking for


print(pythagorean_triplets())













end = time()

print("Time:",end-start)