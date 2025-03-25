#include <iostream>
#include <vector>
#include <algorithm>
#include <string>


using namespace std;

// Using the Factorial_number_system:  https://en.wikipedia.org/wiki/Factorial_number_system

int factorial(int n);

int main(){
    vector<int> digits = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int num_perm = 1000000 - 1;
    int n = digits.size() - 1;
    int indx, n_fact;
    while (num_perm != 0){
        n_fact = factorial(n);
        indx = num_perm / n_fact;
        num_perm -= (indx * n_fact);
        n -= 1;
        cout << digits[indx];
        // remove the element from that index from the digits
        digits.erase(digits.begin() + indx);
    }
    cout << digits[0];
    cout << endl;
    return 0;
}

int factorial(int n){
    if (n == 1){
        return 1;
    }
    return n * factorial(n - 1);
}
