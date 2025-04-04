#include <iostream>
#include <cmath>
#include <vector>
#include <unordered_set> 
#include <assert.h>
#include <unordered_map>
#include <set> 
#include <algorithm>
#include <cctype> // Required for toupper()
using namespace std;


// Make header file for
// a ^ b with carry and significant digits.

// then I can easily solve 48

// also to get the first and last digits of numbers and to chop off these numbers.
// check n_digital
// get order (get_* returns an int or smth)


// does the sum over the smaller array first.
// perform carry operations.

// add "rotate" method for 35. 


// easy to solve now: 48


namespace pe_methods {
    // Some conventions, all methods that start with 'check' return a bool


    bool check_vec_palindrome(const vector<int> &vec){
        bool is_palindrome = true;
        int right_ptr = vec.size() -1;
        for (int i = 0; i < vec.size() / 2;i++){
            if (vec[i] != vec[right_ptr]) return false;
            right_ptr -= 1;
        }
        return is_palindrome;
    }


    vector<int> get_dec_to_base_n(int n, int num_base){
        // Only for base 2-9
        vector<int> new_num;
        int rem, temp;
        while (n > 0){
            new_num.insert(new_num.begin(), n % num_base);
            n /= num_base;
        }
        return new_num;
    }



    int get_char_alphabet_pos(char c){
        unordered_map<char, int> letter_to_num = {
            {'A', 1}, {'B', 2}, {'C', 3}, {'D', 4}, {'E', 5}, {'F', 6},
            {'G', 7}, {'H', 8}, {'I', 9}, {'J', 10}, {'K', 11}, {'L', 12},
            {'M', 13}, {'N', 14}, {'O', 15}, {'P', 16}, {'Q', 17}, {'R', 18},
            {'S', 19}, {'T', 20}, {'U', 21}, {'V', 22}, {'W', 23}, {'X', 24},
            {'Y', 25}, {'Z', 26}, {'"', 0}
        };
        // Make capital
        char capital = toupper(c);
        return letter_to_num[capital];
    }

    bool check_integer(const double n) {
        return std::abs(n - std::round(n)) < 1e-9; // Safer floating-point comparison
    }

    bool check_triangular(const long long &n){
        assert (n > 0);
        double to_check = (-1 + sqrt(1 + 8 * n))/2.0;
        return check_integer(to_check);
    }

    bool check_pentagonal(const long long &n){
        assert (n > 0);
        double to_check = (1 + sqrt(1 + 4 * 3 * 2 * n))/6.0;
        return check_integer(to_check);
    }

    bool check_hexagonal(const long long &n){
        assert (n > 0);
        double to_check = (1 + sqrt(1 + 4 * 2 * 1 * n))/4.0;
        return check_integer(to_check);
    }

    int factorial(int n){
        assert (n >= 0); 
        if (n == 0) return 1;
        return n * factorial(n - 1);
    }

    vector<bool> get_sieved_primes(const int &upper_limit){
        assert(upper_limit > 0);
        vector<bool> sieved_primes(upper_limit, true);
        // 0 and 1 are not prime
        sieved_primes[0] = false;
        sieved_primes[1] = false;
        int sqrt_ul = sqrt(upper_limit);
        for (int i=2; i < sqrt_ul; i++){
            if (!sieved_primes[i]) continue;
            for (int j=i*i; j < upper_limit; j += i){
                sieved_primes[j] = false;
            }
        }
        return sieved_primes;
    }


    vector<int> get_prime_list(const int &upper_limit){
        const vector<bool> primes_sieved = pe_methods::get_sieved_primes(upper_limit); // probably enough
        vector<int> primes;
        for (int j = 0; j < primes_sieved.size(); j++){
            if (!primes_sieved[j]) continue;
            primes.push_back(j);
        }
        return primes;
    }

    bool check_prime(int &n){
        if (n <= 0){
            return false;
        }
        // Check if a number is prime
        int sqrt_n = sqrt(n);
        for (int i=2; i <= sqrt_n; i++){
            if (n % i == 0){
                return false;
            }
        }
        return true;
    }

    int get_order(const int &n){
        return log(n)/log(10);
    }

    int get_last_digit(int &n){
        return n % 10;
    }

    void remove_last_digit(int &n){
        n /= 10;
    }

    int get_first_digit(int n){
        return n / pow(10, get_order(n));       
    }
    
    void remove_first_digit(int &n){
        n -= (get_first_digit(n) * pow(10, get_order(n)));
    }

    unordered_set<int> get_digit_set(int n){
        unordered_set<int> digits;
        while (n > 0){
            digits.insert(get_last_digit(n));
            remove_last_digit(n);
        }
        return digits;
    }

    vector<int> get_digit_vec(int n){
        vector<int> digits;
        while (n > 0){
            digits.push_back(get_last_digit(n));
            remove_last_digit(n);
        }
        // cout << "Elements in digit vec ";
        // for (int x : digits) cout << x << " ";
        // cout << endl;
        return digits;
    }

    unordered_set<int> set_union(const unordered_set<int>& set1, const unordered_set<int>& set2) {
        // Insert all elements of set1 into union_set
        unordered_set<int> union_set(set1.begin(), set1.end());
        // Insert elements of set2 (duplicates are automatically ignored)
        union_set.insert(set2.begin(), set2.end());
        return union_set;
    }


    vector<int> get_vec_int_intersection(const vector<int> &vec1, const vector<int> &vec2){
        unordered_set<int> added = {};
        vector<int> intersection;
        int size1 = vec1.size(), size2 = vec2.size();
        assert (size1 > 0);
        assert (size2 > 0);
        const vector<int> &smaller_vec = (size1 < size2) ? vec1 : vec2; // if else statement in one line.
        const vector<int> &larger_vec = (size1 < size2) ? vec2 : vec1; // if else statement in one line.
        // Loop over the smaller set to be more efficient 
        for (int el : smaller_vec){
            if (find(larger_vec.begin(), larger_vec.end(), el) != larger_vec.end()){
                // if (added.count(el) > 0) continue;
                intersection.push_back(el);
                added.insert(el);
            }
        }
        return intersection;
    }

    unordered_set<int> get_uset_intersection(const unordered_set<int> &set1, const unordered_set<int> &set2){
        unordered_set<int> intersection;
        int size1 = set1.size(), size2 = set2.size();
        const unordered_set<int> &smaller_set = (size1 < size2) ? set1 : set2; // if else statement in one line.
        const unordered_set<int> &larger_set = (size1 < size2) ? set2 : set1; // if else statement in one line.
        // Loop over the smaller set to be more efficient 
        for (int el : smaller_set){
            if (larger_set.count(el)){
                intersection.insert(el);
            }
        }
        return intersection;
    }

    void rotate(int &n){
        // Goes from 971 -->  719 
        // When applied again 719 --> 197 --> 917
        int first_digit = get_first_digit(n);
        remove_first_digit(n);
        // cout << "remove last " << n << endl;
        n *= 10;
        // cout << "2 " << n << endl;
        n += first_digit;
        // cout << "3 " << n << endl;
    }

    bool check_n_digital(int n){
        // Check if the numbers 1, 2, 3, ...., order(n) are in the number n
        int order = get_order(n);
        unordered_set<int> all_digits;
        for (int i=1; i < order + 2; i++){
            all_digits.insert(i);        
        }
        // Get the digits that are in the number n
        unordered_set<int> digits;
        while (n > 0){
            digits.insert(get_last_digit(n));
            remove_last_digit(n);
        }
        return all_digits == digits;
    }



    int reverse(int n){
        bool negative = false;
        if (n < 0){
            negative = true;
            n *= -1;
        }
        // Reverse an integer.
        // Convenient for palindrome checking
        int reversed = 0;
        int last_digit;
        while (n != 0){
            last_digit = n - 10 * (n / 10);
            n /= 10;
            reversed = 10 * reversed + last_digit;
        }
        if (negative) n *= -1;
        return reversed;
    }


    bool check_set_n_digital(const unordered_set<int>& set, const int n){
        unordered_set<int> check;
        for (int i = 1; i <= n; i++) check.insert(i);
        return check == set;
    }


    // Check for carry at 96, 25

    namespace vec {
        void perform_carry(vector<int> &vec){
            for (int i = 0; i < vec.size(); i++){
                if (vec[i] < 10) continue;
                // We need to perform a carry
                vec[i + 1] += (vec[i] / 10); // Dividing by 10 chops off the last digit.
                vec[i] %= 10; // Only keep the last number
            }
        }
        
        void multiply_by_n(vector<int> &vec, int n){
            for(int i = 0; i < vec.size(); i++){
                vec[i] *= n;
            }
            perform_carry(vec);
        }
        
        vector<int> add_two_vectors(vector<int> &vec1, vector<int> &vec2){
            assert (vec1.size() == vec2.size()); // Make sure that the vectors have the same size
            vector<int> summed_vec(vec1.size(), 0);
            for (int i=0; i < vec1.size(); i++){
                summed_vec[i] = (vec1[i] + vec2[i]);
            }
            perform_carry(summed_vec);
            return summed_vec;
        }
        
        vector<int> get_a_power_b(int a, int b, int size_alloc){
            vector<int> a_pow_b(size_alloc, 0);
            a_pow_b[0] = a;
            for(int j=1; j < b; j++){
                multiply_by_n(a_pow_b, a);
            }
            return a_pow_b;
        }

        void print_vec(vector<int> &vec){
            bool leading_zeroes = true;
            for (int i = vec.size() - 1; i >= 0; i--){
                if (vec[i] != 0) leading_zeroes = false;
                if (!leading_zeroes) cout << vec[i]; 
            }
            cout << endl;
        }

        u_int64_t vec_to_int(vector<int> &vec){
            u_int64_t vec_sum = 0;
            int size_vec = vec.size();
            bool leading_zeroes = true;
            int n = 0;
            for (int i = vec.size() - 1; i >= 0; i--){
                n += 1;
                if (vec[i] != 0) leading_zeroes = false;
                if (leading_zeroes) continue;
                u_int64_t to_add = pow(10,size_vec - n) * vec[i];
                vec_sum += to_add;
            }
            return vec_sum;
        }

    } // end namespace vec


} // end namespace pe_methods