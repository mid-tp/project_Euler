#include "pe_helpers.h"

int main(){

    vector<int> a_p_b = pe_methods::vec::get_a_power_b(15, 14, 40);

    pe_methods::vec::print_vec(a_p_b);
    u_int64_t n = pe_methods::vec::vec_to_int(a_p_b);
    cout << n << endl;

    return 0;
}