#include "pe_helpers.h"

int main(){
    unordered_set<int> to_check;
    vector<int> digits;
    int upper_lim = 100000;
    int n, i_copy;
    bool stop;
    // should not do set, but vec. Set unique, does not count for duplicates.... :/ 
    for (int i = 1; i <= upper_lim; i++){
        // Reset the variables.
        stop = false;
        digits.clear();
        to_check.clear();
        to_check = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        n = 0;
        // Keep multiplying by 1, 2, 3, ..., n until:
        // - The set is empty --> We found a 9-digital product
        // - We want to remove an element that is not in the set --> go to the next number
        while ((!stop) && to_check.size() > 0){
            n += 1;
            i_copy = i * n;
            // Get the digits from i_copy
            digits = pe_methods::get_digit_vec(i_copy);
            // Check if the digits are in the set 'to_check' set.
            for (int digit : digits){
                if (to_check.count(digit) == 0){
                    stop = true;
                    break;
                } 
                to_check.erase(digit);          
            }
        }
        if (stop) continue; // If we stopped prematuraly, we skip
        if (to_check.size() != 0) continue;
        // Print to inspect which one is the largest
        cout << "i = " << i << " n = " << n << endl;
        int temp;
        for (int j = 1; j <= n; j++){
            temp = j * i;
            cout << temp;
        }
        cout << endl << endl;
    }
    cout << endl;
    return 0;
}