#pragma once
#include <vector>
#include <iostream>
#include <cmath>
#include <unordered_set> 
#include <set> 
#include <vector>
#include <unordered_map>

using namespace std;
namespace pe_methods {

    // Random functions
    int factorial(int n);


    // Prime methods
    bool check_prime(int &n);
    std::vector<bool> get_sieved_primes(int &upper_limit);

    // Digit manipulation/checking
    void rotate(int &n);
    void remove_first_digit(int &n);
    int get_first_digit(int n);
    int get_order(int &n);
    int get_last_digit(int &n);
    void remove_last_digit(int &n);
    bool check_n_digital(int n);
    int reverse(int n);


    // Big number calculations
    namespace vec {
        void multiply_by_n(vector<int> &vec, int n);
        void perform_carry(vector<int> &vec);
        vector<int> add_two_vectors(vector<int> &vec1, vector<int> &vec2);
        vector<int> get_a_power_b(int a, int b, int size_alloc);
        void print_vec(vector<int> &vec);
        u_int64_t vec_to_int(vector<int> &vec);
    }

}

