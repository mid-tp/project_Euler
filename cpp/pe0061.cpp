#include "pe_helpers.h"



// int get_last_two_digits(int n){
//     int m = 0;
//     int temp = pe_methods::get_and_remove_last_digit(n);
//     m += temp;
//     temp = pe_methods::get_and_remove_last_digit(n);
//     m += 10 * temp;
//     return m;
// }

// int get_first_two_digits(int n){
//     int m = 0;
//     int temp = pe_methods::get_and_remove_first_digit(n);
//     m += 10 * temp;
//     temp = pe_methods::get_and_remove_first_digit(n);
//     m += temp;
//     return m;
// }

void generate_all_numbers(vector<tuple<int, string>> &special_nums){
    // generate all the 4-digit numbers
    tuple<int, string> num;
    int val;
    for (int i=1; i < 300; i++){ // Bound should be high enough
        // triangle
        val = pe_methods::get_triangle_num(i);
        if ((val > 1000) && (val < 10000)) special_nums.push_back({val, "triangle"});

        // square
        val = pe_methods::get_square_num(i);
        if ((val > 1000) && (val < 10000)) special_nums.push_back({val, "square"});

        // pentagonal
        val = pe_methods::get_pentagonal_num(i);
        if ((val > 1000) && (val < 10000)) special_nums.push_back({val, "penta"});

        // hexagonal
        val = pe_methods::get_hexagonal_num(i);
        if ((val > 1000) && (val < 10000)) special_nums.push_back({val, "hexa"});

        // heptagonal
        val = pe_methods::get_heptagonal_num(i);
        if ((val > 1000) && (val < 10000)) special_nums.push_back({val, "hepta"});

        // octagonal
        val = pe_methods::get_octagonal_num(i);
        if ((val > 1000) && (val < 10000)) special_nums.push_back({val, "octa"});
    }
}


void print_vec(vector<int>& vec){
    cout << "PRINT VEC: ";
    for (int i = 0; i < vec.size(); i++) cout << vec[i] << " ";
    cout << endl;
}

string get_last_two_digits_str(int n) {
    string s = to_string(n);
    int len = s.length();
    assert(len >= 2); // Make sure the number has at least 2 digits
    return s.substr(len - 2, 2); // Last two characters
}

string get_first_two_digits_str(int n) {
    string s = to_string(n);
    assert(s.length() >= 2); // Ensure at least 2 digits
    return s.substr(0, 2); // First two characters
}


bool add_possible(tuple<int, string> tup, vector<tuple<int, string>> &vec){
    assert (vec.size() < 6); // make sure we cannot be done already
    string current_type = get<1>(tup);
    int current_num = get<0>(tup);

    // The element cannot be in the set already, the first two digits should match the last two digits

    if (find(vec.begin(), vec.end(), tup) != vec.end()) return false; // If the elemen is in the set, we do not add it again.

    // Check if the current type is already in the vec.
    // This cannot happen, if so, return false.
    for (const auto& tup : vec){
        string type = get<1>(tup);
        if (type == current_type) return false;
    }
    
    // get the first two elements of the tup, and the last two digits of the prev added el in the vec
    // check if they are the same. 
    // Also loop over the names of the nums, if that is the same as the "type" we want 
    // to add, do not add it.
    tuple<int, string> prev_added = vec.back();
    string last_digits = get_last_two_digits_str((int) get<0>(prev_added));
    string first_digits = get_first_two_digits_str(current_num);
    if (last_digits != first_digits) return false;

    // We checked all the possibilities.
    // The element can be added
    return true;
}

bool check(const vector<tuple<int, string>> &roman_nums, vector<tuple<int, string>> &special_set){
    if (special_set.size() == 6){
        // Check if the first and last element match
        tuple<int, string> first_tup = special_set.front();
        tuple<int, string> last_tup = special_set.back();
        string last_digits = get_last_two_digits_str((int) get<0>(last_tup));
        string first_digits = get_first_two_digits_str((int) get<0>(first_tup));
        return last_digits == first_digits;
    } 

    // The backtrack
    for (const auto& tup : roman_nums){
        if (!add_possible(tup, special_set)) continue;
        special_set.push_back(tup);
        if (check(roman_nums, special_set)) return true;
        // remove the tuple
        special_set.pop_back();
    }
    return false;
}


void print_special_vec(vector<tuple<int, string>> vec){
    for (auto x : vec) cout << get<0>(x) << " (" << get<1>(x) << ") " << endl;
}


int main(){
    vector<tuple<int, string>> roman_nums;
    generate_all_numbers(roman_nums);
    vector<tuple<int, string>> special_set;

    // print_special_vec(roman_nums);

    for (auto tup : roman_nums){
        special_set.clear();
        special_set.push_back(tup);
        if (check(roman_nums, special_set)) break;
    }

    int total = 0;
    for (auto x : special_set){
        total += (int) get<0>(x);
        cout << get<0>(x) << " (" << get<1>(x) << ") ";
    } 

    cout << endl << total << endl;
    cout << endl;
    return 0;
}





