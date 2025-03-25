#include <iostream>
#include <cmath>

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
    u_int16_t count = 0;
    int n = 1;
    while (count != 10001){
        n += 1;
        if (isprime(n)){
            count += 1; 
        }
    }
    cout << "The " << count << "-st prime number is " << n << endl;

    return 0;
}