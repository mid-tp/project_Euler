#include "pe_helpers.h"



int get_digit_fact_sum(int n, unordered_map<int, int>& n_to_fact){
    int total = 0;
    int digit;
    while (n != 0){
        digit = pe_methods::get_last_digit(n);
        total += n_to_fact[digit];
        pe_methods::remove_last_digit(n);
    }
    return total;
}

int main(){

    int lim = 1000000;


    unordered_map<int, int> n_to_fact = {};
    for (int i = 0; i < 10; i++) n_to_fact[i] = pe_methods::factorial(i);

    int digit_fact_sum;
    int counter;
    int num_chains = 0;
    for (int n = 1; n < lim; n++){
        unordered_set<int> seen = {n};
        counter = 1;
        digit_fact_sum = get_digit_fact_sum(n, n_to_fact);
        while (seen.count(digit_fact_sum) == 0){
            // Add the digit_fact sum to the seen set
            seen.insert(digit_fact_sum);
            counter += 1;
            digit_fact_sum = get_digit_fact_sum(digit_fact_sum, n_to_fact);
        }
        if (counter == 60) num_chains += 1;
    }   

    cout << num_chains << endl;


    cout << endl;
    return 0;
}