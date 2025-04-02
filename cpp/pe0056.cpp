#include "pe_helpers.h"

int get_digit_sum(vector<int>& vec){
    int digit_sum = 0;
    for (int x : vec) digit_sum += x;
    return digit_sum;
}

int main(){
    int digit_sum, max_digit_sum = 0;
    vector<int> a_pow_b;
    int lim = 100;
    for (int a = 1; a < lim; a ++){
        for (int b = 1; b < lim; b++){
            a_pow_b = pe_methods::vec::get_a_power_b(a, b, 500);
            digit_sum = get_digit_sum(a_pow_b);
            max_digit_sum = (digit_sum > max_digit_sum) ? digit_sum : max_digit_sum;
        }

    }
    cout << max_digit_sum << endl;
    cout << endl;
    return 0;
}