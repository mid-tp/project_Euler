#include <iostream>
#include <cmath>
#include "pe_helpers.h"
using namespace std;


int main() {
    int limit = 2000000;
    u_int64_t total = 0;

    for (int i=0; i < limit; i++){
        if (!pe_methods::check_prime(i)) continue;
        total += i;
    }
    cout << total << endl;
    return 0;
}