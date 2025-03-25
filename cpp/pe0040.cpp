#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

void add_digits(int n, vector<int> &arr);


int main(){
    vector<int> digits;

    for (int i = 1; i < 100000;i++){
        add_digits(i, digits);
    }

    int index = 1;
    int total = 1;
    for (int j = 0; j < 6; j++){
        total *= digits[(int) pow(10, j) - 1];

    }
    cout << total << endl;
    cout << endl;
    return 0;
}

void add_digits(int n, vector<int> &arr){
    vector<int> rev_digits;

    while (n != 0){
        rev_digits.push_back(n % 10);
        n /= 10;
    }

    // Now add them in reverse order.
    for(int i = rev_digits.size() - 1; i >= 0; i--){
        arr.push_back(rev_digits[i]);
    }
}