#include "pe_helpers.h"



int main(){
    int size_alloc = 15;
    vector<int> a_b = pe_methods::vec::get_a_power_b(1, 1, size_alloc);
    vector<int> zero_vec = pe_methods::vec::get_a_power_b(0, 1, size_alloc);
    vector<int> sum_vec = pe_methods::vec::add_two_vectors(a_b, zero_vec);
    vector<int> next_vec;
    int upper_limit = 1000;
    for (int i = 2; i <= upper_limit; i++){
        a_b = pe_methods::vec::get_a_power_b(i, i, size_alloc);
        sum_vec = pe_methods::vec::add_two_vectors(a_b, sum_vec);
    }


    for (int i = 9; i >= 0; i--) cout << sum_vec[i];
    cout<< endl;

    return 0;
}