#include <iostream>
#include <vector>
using namespace std;

vector<int> COINS = {1, 2, 5, 10, 20, 50, 100, 200};

int count_ways(int res, int coin_index) {
    if (res == 0) return 1;  // Found a valid combination
    if (res < 0) return 0;   // Invalid case

    int total = 0;
    for (int c = coin_index; c < COINS.size(); c++) {
        total += count_ways(res - COINS[c], c);  // Remove extra loop
    }
    return total;
}

int main() {
    cout << "\nWe can make 200 in " << count_ways(200, 0) << " different ways\n";
    return 0;
}
