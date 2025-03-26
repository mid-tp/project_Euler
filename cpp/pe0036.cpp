#include "pe_helpers.h"


int main(){
    int upper_lim = 1000000;
    vector<int> new_num;
    int total = 0;

    for (int i = 0; i < upper_lim; i++){
        if (i != pe_methods::reverse(i)) continue;
        new_num = pe_methods::get_dec_to_base_n(i, 2);
        if (!pe_methods::check_vec_palindrome(new_num)) continue;
        cout << i << endl;
        total += i;
    }
    cout << total;
    cout << endl;



    return 0;
}