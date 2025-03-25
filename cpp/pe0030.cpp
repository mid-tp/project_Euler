#include "pe_helpers.h"


bool power_fifth_sum(int n);

int main(){
    int total = 0;
    for (int i=10;i < 1000000;i++){
        if (!power_fifth_sum(i)) continue;
        cout << i << endl;
        total += i;
    }
    cout << total << endl;
    cout << endl;
    return 0;
}

bool power_fifth_sum(int n){
    int fifth_sum = 0, n_copy = n;
    int digit;
    while (n_copy != 0){
        digit = pe_methods::get_last_digit(n_copy);
        fifth_sum += pow(digit, 5);
        pe_methods::remove_last_digit(n_copy);
    }
    return fifth_sum == n;
}