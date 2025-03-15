#include <iostream>
#include <cmath>
#include "pe_helpers.h"
using namespace std;


int mod(int n);
int quad_form(int n, int a, int b);
bool isprime(int n);

int main() {
    int consec_prime_count, n, prod_a_b, qf;
    int max_consec_count = -1000;
    for (int a = -999; a < 1000; a++){
        for (int b = -999; b < 1001; b++){
            n = 0;
            qf = quad_form(n, a, b);
            while (qf > 0 && isprime(qf)){
                n += 1;
                qf = quad_form(n, a, b);
                // cout << endl << endl << "a = " << a << " b = " << b << " n = " << n << " qf = " << qf << " " << isprime(qf) <<   endl;
            }
            // if (consec_prime_count > 35){
            //     cout << a << " and " << b << " count --> " << consec_prime_count << endl;
            // }
            if (n > max_consec_count){
                max_consec_count = n;
                prod_a_b = a * b;
                cout << "New max for a = " << a << " and b = " << b << " consec_num = " << consec_prime_count << " prod_ab = " << prod_a_b <<   endl;
            }
        }
    } 
    cout << "a * b = " << prod_a_b << endl;
    cout << endl;


}

int mod(int n){
    if (n < 0) return -n;
    return n;
}

int quad_form(int n, int a, int b){
    return n*n + a * n + b;
}

bool isprime(int n){
    // Check if a number is prime
    int sqrt_n = sqrt(n);
    for (int i=2; i <= sqrt_n; i++){
        if (n % i == 0){
            return false;
        }
    }
    return true;
}