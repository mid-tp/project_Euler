#include <iostream>
#include <cmath>

using namespace std;

bool isprime(int n){
    int sqrt_n = sqrt(n);
    for (int i=2; i <= sqrt_n; i++){
        if (n % i == 0){
            return false;
        }
    }
    return true;
}

int main(){
    long int num = 600851475143;
    int sqrt_num = sqrt(num);
    for (int i=2;i < sqrt_num; i++){
        if (num % i == 0 && isprime(i)){
            cout << i << endl;
        }
    }
    return 0;
}