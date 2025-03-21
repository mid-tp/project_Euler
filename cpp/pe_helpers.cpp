#include <iostream>
#include <cmath>
#include <vector>
#include <unordered_set> 
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

}