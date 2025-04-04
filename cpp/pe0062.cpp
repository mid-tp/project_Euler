#include "pe_helpers.h"
#include <tuple>



string get_string_of_digits(vector<int> vec){
    pe_methods::vec::remove_leading_zeroes(vec);
    sort(vec.begin(), vec.end()); // sort the digits
    string digits;
    for (int x : vec) digits += x + '0';
    return digits;
}




int main(){

    unordered_map<string, int> digit_count;
    unordered_map<string, vector<int>> digits_to_nums;
    int limit = 1 << 25;
    for (int i = 1; i < limit; i++){
        vector<int> i_cubed = pe_methods::vec::get_a_power_b(i, 3, 30);
        string s = get_string_of_digits(i_cubed);
        digit_count[s] += 1;

        // Keep track of which cube of i makes up these digits
        if (digits_to_nums[s].size() == 0) digits_to_nums[s] = {i};
        else digits_to_nums[s].push_back(i);
        if (digit_count[s] == 5){
            cout << "FOUND IT: ";
            int smallest = digits_to_nums[s].front();
            vector<int> smallest_cubed = pe_methods::vec::get_a_power_b(smallest, 3, 30);
            pe_methods::vec::print_vec(smallest_cubed);
            break;
        }
    }
    cout << endl;
    return 0;

}