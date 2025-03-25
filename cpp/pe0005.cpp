#include <iostream>
using namespace std;

bool remainder_check(int num){
    int rem;
    for(int i=1; i<=20;i++){
        rem = num / i;
        if (num % i != 0){
            return false;
        }
    }
    return true;
}

int main(){
    int n=0;
    bool done = false;

    while (!done){
        n += 20;
        if (remainder_check(n)){
            done = true;
        }
    }
    cout << "Largest number evenly divisible by 10 is " << n << endl;

    return 0;
}


