#include <iostream>
#include <cmath>

using namespace std;


int num_divisors(int n){
    if (n <= 0){
        return 0;
    }
    int num_divisors=0;
    for (int i=1; i <=sqrt(n); i++){
        if (n % i == 0){
            num_divisors += 2;
        }
    }
    
    return num_divisors;
}

int main(){
    cout << "Enter number of divisors" << endl;
    int div_limit;
    cin >> div_limit;
    int num_div = 0;
    int trian_num = 1;
    int j = 1;
    while (num_div < div_limit){
        num_div = num_divisors(trian_num);
        j++;
        trian_num += j;
    }
    cout << "First triangular number with " << div_limit << " divisors is " << trian_num - j << endl;
    return 0;
}