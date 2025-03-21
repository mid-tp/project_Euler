#include <iostream>
#include <cmath>
#include <vector>
#include <unordered_set> 
#include <assert.h>
#include <set> 
using namespace std;


// Make header file for
// a ^ b with carry and significant digits.

// then I can easily solve 48

// also to get the first and last digits of numbers and to chop off these numbers.
// check n_digital
// get order (get_* returns an int or smth)


// does the sum over the smaller array first.
// perform carry operations.


namespace pe_methods {
    // Some conventions, all methods that start with 'check' return a bool

    vector<bool> get_sieved_primes(u_int64_t &upper_limit){
        vector<bool> sieved_primes(upper_limit, true);
        u_int64_t sqrt_ul = sqrt(upper_limit);
        for (int i=0; i < sqrt_ul; i++){
            if (!sieved_primes[i]) continue;
            for (int j=i*i; j < upper_limit; j += i){
                sieved_primes[j] = false;
            }
        }
        return sieved_primes;
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

    int get_order(int &n){
        return log(n)/log(10);
    }

    int get_last_digit(int &n){
        return n % 10;
    }

    void remove_last_digit(int &n){
        n /= 10;
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
            cout << "Computing power " << a << " ^ " << b << endl;
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