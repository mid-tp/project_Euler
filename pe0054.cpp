#include "pe_helpers.h"

vector<int> reverse_and_add(vector<int> &vec1){
    // First remove leading zeroes from the numbers
    pe_methods::vec::remove_leading_zeroes(vec1);
    // Create another vector with large enough size, just 50 by default.
    int size_1 = vec1.size();
    vector<int> summed_vec(50, 0);
    for (int i=0; i < size_1; i++){
        summed_vec[i] = (vec1[i] + vec1[size_1 - 1 - i]);
    }
    pe_methods::vec::perform_carry(summed_vec);
    return summed_vec;
}

bool check_palindrome(vector<int> vec){
    pe_methods::vec::remove_leading_zeroes(vec);
    if (vec.size() < 2) return false;
    for (int i = 0; i <= (1 + vec.size()/2); i++){
        // cout << vec[i] << " == " << vec[vec.size() - 1 - i] << endl;
        if (vec[i] != vec[vec.size() - 1 - i]) return false;
    }
    return true;
}

bool is_Lychrel(int num){
    int it_num = 0;
    vector<int> vec = pe_methods::vec::int_to_vec(num);
    while (it_num < 50){
        it_num += 1;
        vec = reverse_and_add(vec);
        // pe_methods::vec::print_vec(vec);
        if (check_palindrome(vec)) return false;
    }
    return true;
}

int main(){
    int total = 0;
    for (int i = 1; i < 10000; i++){
        if (is_Lychrel(i)) total += 1;
    }
    cout << total << endl;
    cout << endl;
    return 0;
}