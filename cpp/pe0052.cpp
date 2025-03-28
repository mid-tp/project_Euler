#include "pe_helpers.h"

int main(){

    int k = 0;
    int k_x;
    bool done = false;
    unordered_set<int> digits;
    while (!done){
        k += 1;
        digits = pe_methods::get_digit_set(k);
        for (int x = 2; x <= 6; x++){
            k_x = k * x;
            unordered_set<int> new_digits = pe_methods::get_digit_set(k_x);
            if (digits != new_digits) break;
            digits = new_digits;
            if (x == 6) done = true;
        }
    }
    cout << k << endl;
    cout << endl;
    return 0;
}