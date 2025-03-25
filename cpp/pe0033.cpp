#include "pe_helpers.h"


int main(){
    vector<int> num_digits, denom_digits, intersection;
    float prod = 1.0;
    int val_intersect;
    float frac, simplified_frac, num, denom;
    int limit = 100;
    for (int i = 10; i <= limit; i++){
        num_digits = pe_methods::get_digit_vec(i);
        for (int j = i + 1; j <= limit; j++){
            // cout << endl << "i = " << i << " j = " << j << endl;
            num_digits = pe_methods::get_digit_vec(i);
            denom_digits = pe_methods::get_digit_vec(j);
            intersection = pe_methods::vec_int_intersection(num_digits, denom_digits);
            // cout << "intersection: ";
            // for (int a : intersection) cout << a << " ";
            // cout << endl;
            if (intersection.size() != 1) continue;
            val_intersect = intersection[0];
            if (val_intersect == 0) continue; // consider the non-trivial examples
            // cout << "Value intersection " << val_intersect << endl;
            // Now check if cancelling the digit in common yields the same result
            frac = (float) i / j;
            // Get the indices of the positions to remove            
            vector<int>::iterator pos_num = find(num_digits.begin(), num_digits.end(), val_intersect);
            vector<int>::iterator pos_denom = find(denom_digits.begin(), denom_digits.end(), val_intersect);
            // Remove the elements 
            if (pos_num != num_digits.end()) num_digits.erase(pos_num);
            if (pos_denom != denom_digits.end()) denom_digits.erase(pos_denom);
            // // Get the only values that are left
            num = num_digits[0], denom = denom_digits[0];
            // cout << "num= " << num << " denom= " << denom << endl;
            if (denom == 0) continue;
            simplified_frac = (float) num / denom;
            // cout << "frac " << frac << " Simplified frac " << simplified_frac << endl;
            if (frac != simplified_frac) continue;
            cout << i << " / " << j << endl;
            // Multiply the denominator
            prod *= simplified_frac;
        }
    }

    cout << "Product: ";
    cout << prod;
    cout << endl;



    return 0;
}