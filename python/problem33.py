# The fraction 49/98 is a curious fraction, as an inexperienced mathematician in attempting to simplify it may
# incorrectly believe that 49/98 = 4/8, which is correct, is obtained by cancelling the 9s.
#
# We shall consider fractions like, 30/50 = 3/5, to be trivial examples.
#
# There are exactly four non-trivial examples of this type of fraction, less than one in value, and containing two digits in the numerator and denominator.
#
# If the product of these four fractions is given in its lowest common terms, find the value of the denominator.

import math
from time import time
from fractions import Fraction

begin = time()
def isprime(num1):
    for i in range(2,int(math.sqrt(num1))+1):
        if (num1 % i) == 0:
            return False
    else:
        return True

def digit_gettter(num):
    """
    This method tells you how many times a digit is present in a number.
    The output is in a dictionary form.
    :param num: an integer value
    :return: a dictionary with as keys the digits, as value how many times they are present.
    """
    digits = {}
    while num != 0:
        last_digit = num % 10
        if last_digit in digits.keys():
            digits[last_digit] += 1
        else:
            digits.update({last_digit:1})
        num = num // 10
    return digits

def shareDigit(num1,num2):
    """
    Checks if two integer numbers have a digit in common.
    We will restrict ourselves to integers with 2 digits only.
    Also, we assume that num1 is always stricly smaller than num2.
    :param num1: integer
    :param num2: integer
    :return: -1 if no digits match. If the number share a digit, the digit itself and its index of num1 num2
    """
    digitNum1 = digit_gettter(num1)
    digitNum2 = digit_gettter(num2)
    for digit in digitNum1.keys():
        if digit in digitNum2.keys():
            print(digit)
            charDigit = str(digit)
            strNum1 = str(num1)
            strNum2 = str(num2)
            print(charDigit)
            return digit,strNum1.index(charDigit),strNum2.index(charDigit)
    return -1

def removeIndexFromInteger(num, indexToRemove):
    """
    We receive an integer and the index of the digit to be removed.
    So 25,1 will have as result 2
    34455,4 --> 3445
    :param num: an integer
    :param indexToRemove: an integer
    :return: an integer, without the digit indicated by the index.
    """
    strNum = str(num)
    return int(strNum[:indexToRemove] + strNum[indexToRemove+1:])

print(removeIndexFromInteger(34455, 3))

primeSet = set()
for i in range(11,100):
    if isprime(i):
        primeSet.add(i)

setl = set()

upBound = 300
for nume in range(11,upBound):
    if not (nume % 10)==0:
        for denom in range(nume+1,upBound):
            if not (denom % 10) == 0:
                potential = shareDigit(nume,denom)
                if potential != -1:
                    digit = potential[0]
                    # print("\n",digit,nume,denom)
                    pos1 = potential[1]
                    pos2 = potential[2]
                    newNume = removeIndexFromInteger(nume, pos1)
                    newDenom = removeIndexFromInteger(denom, pos2)
                    if nume/denom == newNume/newDenom:
                        setl.add((nume,denom))

print(setl)
#large set {(196, 294), (294, 392), (707, 909), (606, 707), (604, 906), (134, 737), (55, 253), (77, 176), (202, 505), (217, 775), (396, 594), (242, 341), (401, 802), (484, 781), (186, 465), (77, 275), (385, 682), (198, 396), (398, 995), (296, 592), (505, 808), (101, 808), (286, 781), (693, 792), (302, 604), (484, 583), (297, 891), (197, 394), (162, 648), (264, 363), (138, 345), (396, 792), (49, 98), (139, 695), (149, 894), (176, 374), (352, 451), (286, 583), (398, 796), (286, 385), (98, 294), (198, 594), (495, 792), (165, 363), (196, 392), (66, 264), (154, 253), (498, 996), (491, 982), (176, 572), (165, 462), (394, 591), (492, 984), (197, 591), (187, 484), (198, 792), (143, 242), (233, 932), (201, 402), (299, 897), (303, 808), (66, 462), (104, 208), (536, 737), (103, 206), (96, 192), (49, 294), (187, 385), (396, 891), (403, 806), (226, 565), (495, 693), (203, 406), (164, 656), (101, 505), (133, 532), (194, 291), (264, 561), (297, 594), (334, 835), (134, 335), (99, 792), (119, 595), (44, 143), (202, 808), (202, 909), (168, 672), (99, 693), (44, 242), (116, 464), (44, 341), (19, 95), (77, 374), (179, 895), (363, 561), (303, 404), (77, 473), (583, 781), (606, 808), (191, 955), (193, 965), (166, 664), (55, 154), (363, 462), (404, 808), (737, 938), (49, 196), (133, 931), (404, 909), (99, 495), (22, 121), (183, 732), (101, 404), (304, 608), (88, 781), (596, 894), (583, 682), (386, 965), (34, 238), (88, 682), (606, 909), (427, 976), (234, 936), (275, 671), (494, 988), (572, 671), (88, 583), (249, 996), (297, 495), (98, 392), (402, 603), (101, 909), (33, 132), (88, 484), (335, 737), (385, 484), (306, 765), (497, 994), (83, 332), (603, 804), (201, 804), (199, 796), (374, 572), (594, 693), (505, 707), (66, 561), (473, 572), (268, 469), (136, 238), (97, 291), (101, 202), (39, 975), (199, 597), (249, 498), (594, 792), (303, 606), (597, 995), (707, 808), (99, 594), (134, 536), (169, 676), (187, 286), (176, 473), (198, 495), (98, 196), (106, 265), (202, 707), (297, 396), (49, 392), (198, 297), (303, 909), (462, 561), (297, 693), (198, 693), (204, 306), (77, 572), (305, 854), (202, 404), (66, 165), (77, 671), (101, 606), (88, 286), (396, 495), (102, 306), (99, 396), (484, 682), (404, 707), (473, 671), (505, 606), (385, 781), (88, 187), (591, 985), (66, 363), (99, 297), (253, 451), (167, 668), (39, 195), (199, 995), (404, 505), (306, 408), (404, 606), (161, 644), (266, 665), (202, 303), (55, 451), (159, 795), (275, 473), (102, 408), (33, 231), (602, 903), (216, 864), (374, 671), (101, 707), (199, 398), (163, 652), (134, 938), (594, 891), (299, 598), (67, 469), (16, 64), (149, 298), (496, 992), (206, 309), (536, 938), (202, 606), (67, 268), (808, 909), (26, 65), (532, 931), (34, 136), (303, 707), (112, 616), (399, 798), (13, 325), (394, 985), (493, 986), (59, 295), (197, 985), (55, 352), (398, 597), (286, 484), (262, 655), (165, 264), (97, 194), (495, 891), (27, 756), (346, 865), (303, 505), (499, 998), (792, 891), (224, 728), (187, 583), (505, 909), (101, 303), (203, 609), (298, 596), (99, 198), (301, 903), (156, 858), (349, 698), (449, 898), (146, 365), (149, 596), (201, 603), (302, 906), (693, 891), (154, 352), (682, 781), (301, 602), (402, 804), (335, 938), (796, 995), (79, 395), (187, 682), (178, 979), (275, 374), (88, 385), (176, 275), (99, 891)}

#ALTERNATIVE SOLUTION
#REWRITE FRACTION ab/bc = a/c to --> (10a+b)/(10b+c)=a/c --> c = (10ab)/(9a+b)
#Then we simply have to loop over a and b in range(1,10) and check when c is a perfect integer.
#Only restricted to 2 digit numbers. My solution can be extended to as many digits as wanted.

# fracList = []
# for a in range(1,10):
#     for b in range(a+1,10):
#         c = (10*a*b)/(9*a+b)
#         if c == int(c):
#             print(Fraction(int(10*a+b),int(10*b+c)))

print("TIME: ",time()-begin)





