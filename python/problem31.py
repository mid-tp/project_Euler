# In England the currency is made up of pound, £, and pence, p, and there are eight coins in general circulation:
#
#     1p, 2p, 5p, 10p, 20p, 50p, £1 (100p) and £2 (200p).
#
# It is possible to make £2 in the following way:
#
#     1×£1 + 1×50p + 2×20p + 1×5p + 1×2p + 3×1p
#
# How many different ways can £2 be made using any number of coins?

#Clearly recursion is the way to go here.


# return currencyWays(num - 1, diffWays) + currencyWays(num - 2, diffWays) + currencyWays(num - 5,
#                                                                                         diffWays) + currencyWays(
#     num - 10, diffWays) + currencyWays(num - 20, diffWays) + currencyWays(num - 50, diffWays) + currencyWays(num - 100,
#                                                                                                              diffWays) + currencyWays(
#     num - 200, diffWays)

from time import time
begin = time()

class currency:
    def __init__(self):
            self.numberOfWays = 0

    def increase(self):
        self.numberOfWays += 1



    def currencyWays(self,num,index):
        """
        A method that returns in how many ways a value can be made in terms of the English coins
        :param num: an integer value
        :return: the number of ways this integer value can be represented in terms of English coins.
        """
        print("\nNumber",num)
        coins = [200,100,50,20,10,5,2,1]
        while True:
            coin = coins[index]
            diff = num-coin
            if (num % coin)==0:
                self.increase()
            if diff >0:
                self.currencyWays(num,index+1)



c = currency()
c.currencyWays(25,0)
print(c.numberOfWays)
print("TIME: ",time()-begin)


