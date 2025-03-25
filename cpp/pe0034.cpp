#include "pe_helpers.h"

unordered_map<int, int> FACTORIAL;

int digit_fact_sum(int n){
    int digit_sum = 0;
    int last_digit;
    int copy_n = n;
    while (copy_n > 0){
        last_digit = pe_methods::get_last_digit(copy_n);
        pe_methods::remove_last_digit(copy_n);
        digit_sum += FACTORIAL[last_digit];
        if (digit_sum > n) return false;
    }
    return digit_sum == n;
}

int main(){
    for(int j = 0; j < 1000; j++){
        FACTORIAL[j] = pe_methods::factorial(j);
    }
    int total = 0;

    for (int i = 10; i < 400000; i++){
        // if (!(i % 100)) cout << "Checking " << i << endl;
        if (!digit_fact_sum(i)) continue;
        cout << i << endl;
        total += i;
    }
    cout << total << endl;
    cout << endl;
    return 0;
}




