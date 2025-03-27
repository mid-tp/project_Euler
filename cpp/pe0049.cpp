#include "pe_helpers.h"

bool contain_same_digits(int n, int m){
    // First check if the order is the same
    int order_n = pe_methods::get_order(n),  order_m = pe_methods::get_order(m);
    if (order_n != order_m) return false;
    unordered_set<int> digits_n = pe_methods::get_digit_set(n), digits_m = pe_methods::get_digit_set(m);
    return digits_m == digits_n;
}

int main(){

    vector<bool> primes_sieved = pe_methods::get_sieved_primes(10000);
    int p1, p2;
    for (int p=0; p < primes_sieved.size(); p++){
        if (!primes_sieved[p]) continue;
        p1 = p + 3330;
        p2 = p1 + 3330;
        if (!((primes_sieved[p1]) && primes_sieved[p2])) continue;
        if ((contain_same_digits(p, p1)) && (contain_same_digits(p1, p2))){
            cout << p << p1 << p2 << endl;
        }
    }
    cout << endl;
    return 0;
}