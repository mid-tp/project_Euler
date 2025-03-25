#include "pe_helpers.h"

int main(){
    int upper_limit = 1000000;
    vector<bool> sieved_primes = pe_methods::get_sieved_primes(upper_limit);
    int total = 13; // start with the 13 such primes below 100;
    for (int p=101; p <upper_limit; p += 2){
        int copy_p = p;
        if (!sieved_primes[p]) continue;
        bool still_prime = true;
        int old_order = pe_methods::get_order(p);
        for (int i = 0; i < pe_methods::get_order(p);i++){
            pe_methods::rotate(p);
            still_prime = (still_prime && sieved_primes[p]);
        }
        int new_order = pe_methods::get_order(p);
        p = copy_p;
        // cout << p << "  " << still_prime << endl;
        if (new_order != old_order) continue; // primes must contain the same number of digits.
        if (!still_prime) continue;
        cout << "Circular prime " << p << endl;
        total += 1;
    }
    cout << endl << "Total amount of circular primes " << total << endl;
    cout << endl;
    return 0;
}