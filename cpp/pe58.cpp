#include <iostream>
#include <cmath>
#include <unordered_set>

using namespace std;

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

int main(){
    int to_add = 3;
    int factor = 2;
    unordered_set<int> primes;
    float prime_percentage = 0.0f;

    // Just pick some large upper bound here
    for (int i = 1; i <= pow(10,6) * 4; i++){
        // Check the stopping condition
        if (isprime(to_add)){
            primes.insert(to_add);
        }
        if (i % 4 == 0){
            prime_percentage = primes.size() / (float) (i + 1);
            if (prime_percentage < 0.1) {
                cout << "The side length/prime ratio of primes is less than is 0.1 is at total side length " << (3 + (i/4 - 1) * 2) << endl;
                break;
            }
            factor += 2;
        }
        to_add += factor;
    }
    return 0;
}