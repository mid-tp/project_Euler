#pragma once
#include <vector>
#include <iostream>
#include <cmath>
#include <unordered_set> 
#include <set> 
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <stdio.h>

#include <fstream>
#include <string>
#include <sstream>

using namespace std;
namespace pe_methods {


    // String/char
    int get_char_alphabet_pos(char c);

    // Random functions
    int factorial(int n);

    bool check_integer(double &n);
    bool check_triangular(int &n);

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
    
    // Vector
    vector<int> get_digit_vec(int n);
    vector<int> vec_int_intersection(const vector<int> &vec1, const vector<int> &vec2);

    // Sets
    unordered_set<int> get_digit_set(int n);
    unordered_set<int> uset_intersection(const unordered_set<int> &set1, const unordered_set<int> &set2);



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

