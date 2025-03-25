#include "pe_helpers.h"


int main(){
    int upper_limit = 100000; // Probably large enough
    vector<bool> primes = pe_methods::get_sieved_primes(upper_limit);
    bool flag;
    int idx;
    for (int i = 3; i < upper_limit; i += 2){
        if (primes[i]) continue; // We do not consider primes
        flag = false;
        for (int j = 1; j < i; j++){
            idx = i - 2 * j * j;
            if (idx < 0) break;
            flag = primes[idx];
            if (flag) break;
        }
        if (flag) continue; // We can write the composite as a prime and 2*square
        cout << "The first odd composite that cannot be written as a prime and twice a square is " << i << endl;
        break;
    }
    cout << endl;
    return 0;
}