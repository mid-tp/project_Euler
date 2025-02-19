#
# Starting with the number 1 and moving to the right in a clockwise direction a 5 by 5 spiral is formed as follows:
#
# 21 22 23 24 25
# 20  7  8  9 10
# 19  6  1  2 11
# 18  5  4  3 12
# 17 16 15 14 13
#
# It can be verified that the sum of the numbers on the diagonals is 101.
#
# What is the sum of the numbers on the diagonals in a 1001 by 1001 spiral formed in the same way?
def grid_diag_sum(gridsize):
    grid = []
    for i in range(1,gridsize**2+1):
        grid.append(i)
    grid = grid[::-1]
    # print(grid)
    init_spaces = gridsize-1
    num_summed = 0
    init_index = 0
    total = grid[init_index]
    for i in range(len(grid)):
        if i-init_index == init_spaces:
            total += grid[i]
            init_index = i
            num_summed +=1
            if num_summed == 4:
                init_spaces-= 2
                num_summed = 0
    return total

# print(grid_diag_sum(5))
# print(grid_diag_sum(7))
print(grid_diag_sum(1001))


