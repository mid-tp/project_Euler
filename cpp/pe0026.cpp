#include "pe_helpers.h"


// Do long division.

vector<int> print_decimal_expansion(int numerator, int denominator, int digits) {
    // DOESN'T WORK FOR 1/10, 10/100, find a fix for this.
    vector<int> decimals;
    int copy_numerator = numerator;
    numerator %= denominator;
    while (decimals.size() < digits){
        numerator *= 10;
        decimals.push_back(numerator / denominator);
        numerator %= denominator;
        if (numerator == 0) break;
    }

    // cout << endl;
    // cout << copy_numerator << " / " << denominator << " = 0.";
    // for (int x : decimals) cout << x;

    return decimals;
}

int detect_cycle(vector<int> decimals){
    // cout <<  endl << "Checking cycle" << endl;
    // return the length of the cycle.
    if (decimals.size() < 10) return 0;
    // make sure the size of the decimals is > 5
    bool equal = true;
    for (int j = decimals.size() - 1; j > decimals.size() - 5; j--){
        equal = (decimals[j] == decimals[j - 1]);
        if (!equal) break;
    }
    if (equal) return 0;

    // Now do a simple lookahead.
    bool done = false;
    int offset = 1;
    int max_k = 4;
    while (!done){
        offset += 1;
        vector<int> look_ahead = vector<int>(decimals.begin(), decimals.begin() + offset);
        for (int k = 1; k <= max_k; k++){
            vector<int> new_look_ahead = vector<int>(decimals.begin() + k * offset, decimals.begin() + (k + 1) * offset);
            equal = (look_ahead == new_look_ahead);
            if (!equal) break;
            if (equal && (k == max_k)){
                done = true;
            }
        }
        // For some numbers we have to delete the first number, or even two...
        // We will do this if we searched through the whole list.
        // cout << "current offset " << offset << endl;
        if (!done && offset == decimals.size()){
            // Remove the first element of the decimals vector.
            // Reset the offset.
            decimals.erase(decimals.begin());
            offset = 1;
            // cout << endl << "REMOVED ELEMENT " << endl;
            // for (auto x : decimals) cout << x;
            // cout << endl;
        }
    }
    return offset;
}

int main(){
    int max_length = 0;
    int max_d = 0;
    for (int i = 1; i <= 1000; i++){
        vector<int> decimals = print_decimal_expansion(1, i, 10000);
        int length = detect_cycle(decimals);
        if (length == 0) continue;
        if (length < max_length) continue;
        cout << endl << "NEW MAX LENGTH FOR 1 / " << i;
        cout << " || Cycle length = " << length << endl;
        max_d =  i;
        max_length = length;
    }

    cout << endl << max_d << " has cycle length: " << max_length << endl;
    cout << endl;
    return 0;
}


