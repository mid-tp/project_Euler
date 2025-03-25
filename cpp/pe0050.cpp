#include <iostream>
#include <cmath>
#include <vector>
#include <assert.h>

using namespace std;


bool isprime(int n){
    // Check if a number is prime
    if (n <= 1) return false;
    int sqrt_n = sqrt(n);
    for (int i=2; i <= sqrt_n; i++){
        if (n % i == 0){
            return false;
        }
    }
    return true;
}

vector<bool> prime_sieve(int n){
    vector<bool> prime_sieved = vector(n, true);
    for (int i=2; i < sqrt(n);i++){
        if (!prime_sieved[i]) continue;
        for (int j = i * i; j < n;j += i){
            prime_sieved[j] = false;
        }
    }
    return prime_sieved;

}


int main(){
    // int upper_limit = 330000;
    int upper_limit = pow(10, 6);
    // int upper_limit = 45;
    vector<bool> sieved_primes = prime_sieve(upper_limit * 2);
    vector<int> primes;

    for (int i = 1; i < upper_limit; i++){
        if (!isprime(i)) continue;
        // i is prime
        primes.push_back(i);
    }

    vector<int> cum_sum_primes = {0, 0};
    cum_sum_primes[1] = primes[0];
    for (int i = 1; i < primes.size(); i++){
        cum_sum_primes.push_back(cum_sum_primes[i] + primes[i]);
        if (cum_sum_primes[i] > upper_limit) break;
    }



    // cum_sum_primes.pop_back();
    // Now just check naively the 
    // The difference in the cumulative sums is the sum of the elements 
    // in that range
    int max_length = 0;
    int max_number = 0;
    int length = 0;
    int sum = 0;

    for (int i = 0; i < cum_sum_primes.size();i++){
        for (int j = i + 1; j < cum_sum_primes.size(); j++){
            sum = cum_sum_primes[j] - cum_sum_primes[i];
            if (sum > upper_limit) break;
            if (!sieved_primes[sum]) continue;
            // cout << "Sum is " << sum << " = " <<  endl;
            // cout << "i = " << i  << " j = " << j << endl; 
            // cout << endl;

            // // The sum is prime
            if ((j - i) > max_length){
                max_length = j - i;
                max_number = sum;
            }
        }

    }
    #if 0

    #endif 

    cout << "Max number " << max_number << " Made out of primes of length " << max_length;
    cout << endl;
    return 0;
}