#include "pe_helpers.h"

// Make header file for
// a ^ b with carry and significant digits.

// then I can easily solve 48

// also to get the first and last digits of numbers and to chop off these numbers.

int main(){

    set<vector<int> > powers;
    int alloc_size = 210; // 100^100 has at most 201 digits, so 210 should be plenty
    int bound = 100;
    // int bound = 5;
    for (int a = 2; a <= bound; a ++){
        for (int b = 2; b <= bound; b++){
            vector<int> a_p_b = pe_methods::vec::get_a_power_b(a, b, alloc_size);
            // pe_methods::vec::print_vec(a_p_b);
            // u_int64_t n = pe_methods::vec::vec_to_int(a_p_b);
            // cout << n << endl;
            powers.insert(a_p_b);
        }
    }
    cout << endl << "Number of distinct powers: ";
    cout << powers.size() << endl;
    cout << endl;
}

