#include "pe_helpers.h"

int count_ways(int res, int coin_index);
// This is gonna be with recursion.

vector<int> COINS = {1, 2, 5, 10, 20, 50, 100, 200};

int main(){
    cout << endl;
    int count = count_ways(200, 0);
    cout << "We can make 200 in " << count << " different ways" << endl;
    cout << endl;
    return 0;
}


int count_ways(int res, int coin_index){
    if (res < 0) return 0;
    if (res == 0) return 1;
    int num_times, coin;
    int total = 0;
    for (int c=coin_index; c < COINS.size(); c++){
        // Check how often the current coin fits 
        // in the res.
        total += count_ways(res - COINS[c], c);
    }
    return total;
}


