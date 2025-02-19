A = """08 02 22 97 38 15 00 40 00 75 04 05 07 78 52 12 50 77 91 08
49 49 99 40 17 81 18 57 60 87 17 40 98 43 69 48 04 56 62 00
81 49 31 73 55 79 14 29 93 71 40 67 53 88 30 03 49 13 36 65
52 70 95 23 04 60 11 42 69 24 68 56 01 32 56 71 37 02 36 91
22 31 16 71 51 67 63 89 41 92 36 54 22 40 40 28 66 33 13 80
24 47 32 60 99 03 45 02 44 75 33 53 78 36 84 20 35 17 12 50
32 98 81 28 64 23 67 10 26 38 40 67 59 54 70 66 18 38 64 70
67 26 20 68 02 62 12 20 95 63 94 39 63 08 40 91 66 49 94 21
24 55 58 05 66 73 99 26 97 17 78 78 96 83 14 88 34 89 63 72
21 36 23 09 75 00 76 44 20 45 35 14 00 61 33 97 34 31 33 95
78 17 53 28 22 75 31 67 15 94 03 80 04 62 16 14 09 53 56 92
16 39 05 42 96 35 31 47 55 58 88 24 00 17 54 24 36 29 85 57
86 56 00 48 35 71 89 07 05 44 44 37 44 60 21 58 51 54 17 58
19 80 81 68 05 94 47 69 28 73 92 13 86 52 17 77 04 89 55 40
04 52 08 83 97 35 99 16 07 97 57 32 16 26 26 79 33 27 98 66
88 36 68 87 57 62 20 72 03 46 33 67 46 55 12 32 63 93 53 69
04 42 16 73 38 25 39 11 24 94 72 18 08 46 29 32 40 62 76 36
20 69 36 41 72 30 23 88 34 62 99 69 82 67 59 85 74 04 36 16
20 73 35 29 78 31 90 01 74 31 49 71 48 86 81 16 23 57 05 54
01 70 54 71 83 51 54 69 16 92 33 48 61 43 52 01 89 19 67 48"""


# TODO:make the bottom left to top right diagonal
# TODO:make a product counter that displays the highest quadruple product.


#The script for 20x20 grid.
#
def str_to_int(input_str): #this is just a function that can handle horizontal units,
    listoflists=[]
    hor_list,ver_list,Rdiag_list,Ldiag_list = [],[],[],[]
    i = 0

    #create the hor list
    while len(hor_list)<20*20: #16=4x4, that is, how many numbers you have in your grid
        hor_list.append((int(A[3*i:(3*i+2)])))
        i+=1

    #create the ver list
    hor_length = len(hor_list)
    count = -1
    for i in hor_list:
        if len(ver_list) == 4*4*(5-4): #4elements each for n times* (n+1-4), where n is the number of rows
            break
        ver_list.append(i)
        count+=1
        for j in range(20,hor_length,20):
            if j+count > hor_length-1:
                break
            else:
                ver_list.append(hor_list[j+count])



    #create the left to right diagonal. down (so start at high top left, end at down right)
    line_counter=1
    for i in range(hor_length):
        if line_counter==1:
            if 19*line_counter - i < 3:  # change the first 3 into 19, it is the index.
                i+=3 #add 3 index places, makes sure you go to the beginning of the next line
                line_counter+=1
        else:
            if 19*line_counter+(line_counter-1)-i < 3: #last index doesn't repeat itself exactly every 19 units, but 19*lc+lc (lc=line_counter)
                i+=3
                line_counter+=1
        if i > hor_length-1: #makes sure the hor_list index is not out of range and that it breaks when there are not enough lines left
            break
        if line_counter==18: #if we hit line 18, no more diagonal units can be added.
            break
        else:
            Rdiag_list.append(hor_list[i])
            count = 0
        for j in range(21, hor_length, 21):  # change 5 into 21 sksk
            if i+j>hor_length-1:
                break
            else:
                Rdiag_list.append(hor_list[j+i])
                count += 1
            if count == 3:  # makes sure only 4 consecutive numbers get added to the list.
                break


    #now create the from bottom left to top right diagonal
    line_counter2=4
    for i in range(60,hor_length):
        if 19*line_counter2+(line_counter2-1)-i<3:
            i+=3
            line_counter2+=1
        if i > hor_length - 1:  # makes sure the hor_list index is not out of range and that it breaks when there are not enough lines left
            break
        Ldiag_list.append(hor_list[i])
        count=0
        for j in range(19,hor_length,19):
            Ldiag_list.append(hor_list[i-j])
            count+=1
            if count==3:
                break

    #now create the product sum maximal finder thingy
    maxsum_hor,maxsum_ver,maxsum_Rdiag,maxsum_Ldiag=0,0,0,0
    numbers_hor,numbers_ver,numbers_Rdiag,numbers_Ldiag = [],[],[],[]

    for i in range(int(len(hor_list) / 4)):  # loop for the horizontal
        sum_hor = hor_list[4 * i] * hor_list[4 * i + 1] * hor_list[4 * i + 2] * hor_list[4 * i + 3]
        if sum_hor > maxsum_hor:
            maxsum_hor = sum_hor
            numbers_hor.extend((hor_list[4 * i + 0], hor_list[4 * i + 1], hor_list[4 * i + 2],hor_list[4 * i + 3]))  # just pick the last 4 #just pick the last 4


    for i in range(int(len(ver_list)/4)): #loop for the ver
        sum_ver= ver_list[4 * i + 0]*ver_list[4 * i + 1]*ver_list[4 * i + 2]*ver_list[4 * i + 3]
        if sum_ver > maxsum_ver:
            maxsum_ver =sum_ver
            numbers_ver.extend((ver_list[4 * i + 0],ver_list[4 * i + 1],ver_list[4 * i + 2],ver_list[4 * i + 3]))

    for i in range(int(len(Rdiag_list)/4)): #loop for the Rdiag
        sum_Rdiag = Rdiag_list[i*0]*Rdiag_list[i*1]*Rdiag_list[i*2]*Rdiag_list[i*3]
        if sum_Rdiag > maxsum_Rdiag:
            maxsum_Rdiag=sum_Rdiag
            numbers_Rdiag.extend((Rdiag_list[4 * i + 0],Rdiag_list[4 * i + 1],Rdiag_list[4 * i + 2],Rdiag_list[4 * i + 3]))

    for i in range(int(len(Ldiag_list)/4)): #loop for the Ldiag
        sum_Ldiag = Ldiag_list[4 * i + 0]*Ldiag_list[4 * i + 1]*Ldiag_list[4 * i + 2]*Ldiag_list[4 * i + 3]
        if sum_Ldiag> maxsum_Ldiag:
            print(sum_Ldiag)
            maxsum_Ldiag=sum_Ldiag
            numbers_Ldiag.extend((Ldiag_list[4 * i + 0],Ldiag_list[4 * i + 1],Ldiag_list[4 * i + 2],Ldiag_list[4 * i + 3]))

    return maxsum_Ldiag,maxsum_Rdiag,maxsum_ver,maxsum_hor, numbers_Ldiag[-4:]

print(str_to_int(A))

