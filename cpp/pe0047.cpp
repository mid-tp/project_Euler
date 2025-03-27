#include "pe_helpers.h"

const vector<int> primes = pe_methods::get_prime_list(1000000); // probably enough

void add_factor(vector<int>& factors, int p){
    bool found = false;
    for (int i = 0; i < factors.size(); i++){
        if (factors[i] % p != 0) continue;
        found = true;
        factors[i] *= p;
    }
    if (!found) factors.push_back(p);
}

vector<int> get_prime_factors(int n){
    assert (n > 0);


    int copy_n = n;
    vector<int> prime_factors;
    if (n == 1){
        prime_factors.push_back(1);
        return prime_factors;
    }


    // Do a separate loop for prime factor 2
    while (n % 2 == 0){
        add_factor(prime_factors, 2);
        n /= 2;
    }

    while(n > 1){
        // We can start from 3 and only check the odd numbers
        for (int p : primes){
            if (p > n) break;
            if (n % p != 0) continue;
            add_factor(prime_factors, p);     
            n /= p;     
        }
    }
    if (n > 1) prime_factors.push_back(copy_n); // n is prime itself

    // cout << "The prime factors of " << copy_n << " are:  ";
    // for (auto x : prime_factors) cout << x << " ";
    // cout << endl;

    return prime_factors;
}


int main(){
    int num_factors = 4;
    int num_ahead = 4;
    bool found = false;
    int counter = 0;
    vector<int> intersection;
    int k = 1;
    while (!found){
        if (counter == num_ahead){
            cout << "WE FOUND IT!!!  " << k - num_ahead + 1 << endl;
            found = true;
            break;
        }
        k += 1;
        vector<int> prime_factors = get_prime_factors(k);
        if (prime_factors.size() != num_factors){
            // We need t start counting again.
            counter = 0;
            continue;
        } 
        if (counter > 0){
            intersection = pe_methods::get_vec_int_intersection(intersection, prime_factors);
            counter = (intersection.size() > 0) ? 0 : counter + 1;// if true, counter is set to 0, otherwise counter + 1
            intersection = prime_factors;
        }
        else if (counter == 0){
             intersection = prime_factors;
             counter += 1;
        }
    }    
    cout << endl;
    return 0;
}


// int main(){
//     for (int i = 1; i < 200; i ++){
//         vector<int> s = get_prime_factors(i);
//     }
// }


// This can be sped up significantly. Very brute force atm
// bool check_condition(int n, const int num_factors, const int num_ahead){
//     // cout << endl << endl << "CHECKING" << endl << endl;
//     // The n + 1, n + 2, ..., n + num_ahead should all have 'num_factors' prime factors
//     // Moreover, the intersection of factors needs to be empty.
//     vector<int> intersection, factors_n, factors_n_1;
//     factors_n = get_prime_factors(n);
//     assert (factors_n.size() == num_factors);
//     int k = 0;
//     while (k < num_ahead - 1){
//         k += 1;
//         factors_n_1 = get_prime_factors(n + k);
//         if (factors_n_1.size() != num_factors){
//             // cout << "check 1" << endl;
//             return false; // If this number doesn't contain 'num_factor' factors, return false.
//         } 
//         // Check if the intersection is empty
//         intersection = pe_methods::get_vec_int_intersection(factors_n, factors_n_1);
//         if (intersection.size() > 0){
//             // cout << "check 2" << endl;
//             return false;
//         } 
//         factors_n = factors_n_1;
//     }
//     return true;
// }

// int main(){
//     int num_factors = 4;
//     int num_ahead = 4;
//     bool found = false;
//     int k = 100;
//     while (!found){
//         k += 1;
//         vector<int> prime_factors = get_prime_factors(k);
//         if (prime_factors.size() != num_factors) continue;
//         // cout << "The prime factors of " << k << " are:  ";
//         // for (auto x : prime_factors) cout << x << " ";
//         // cout << endl;
//         if (!check_condition(k, num_factors, num_ahead)) continue;
//         cout << "WE FOUND IT!!!  " << k << endl;
//         found = true;
//     }    
//     cout << endl;
//     return 0;
// }