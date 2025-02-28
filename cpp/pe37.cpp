#include <iostream>
#include <math.h>
#include <cmath>
using namespace std;


bool isprime(int n){
    // Check if a number is prime
    if (n == 1) return false;
    int sqrt_n = sqrt(n);
    for (int i=2; i <= sqrt_n; i++){
        if (n % i == 0){
            return false;
        }
    }
    return true;
}

void remove_digit_from_left(int &n){
    int order = log10(n);
    int mod = pow(10, order);
    n %= mod;
}

void remove_digit_from_right(int &n){
    n /= 10;
}

bool remains_prime(int n){
    int m = n;
    while(n != 0){
        remove_digit_from_left(n);
        if (!isprime(n)) return false;
        // cout << "n= " << n << " is prime..." << endl;
    }
    while(m != 0){
        remove_digit_from_right(m);
        if (!isprime(m)) return false;
        // cout << "m= " << m << " is prime..." << endl;
    }
    return true;
}


int main(){

    int count = 0;
    int sum = 0;
    // Remove digit from the left
    int p = 1;
    cout << "Truncatable primes: ";
    while (count != 11){
        p++;
        if (!isprime(p)) continue;
        if (p / 10 == 0){
            continue;
        }
        // We are dealing with a prime with more than 1 digit
        if (!remains_prime(p)) continue;
        count++;
        sum += p;

        cout << p << " ";
    }
    cout << endl << "Total sum of truncatable primes is " << sum << endl;
    return 0;
}

