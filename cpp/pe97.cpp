
#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

void perform_carry(vector<int> &vec);
void multiply_by_n(vector<int> &vec, int n);


int main(){
    // First initialize a large enough vector to store all the digits.
    int number_digits = 11;
    vector<int> vec(number_digits, 0);
    vec[0] = 1;

    int big_power = 7830457;
    // Perform a couple of multiplies by 2
    for (int i = 0; i < big_power; i++){
        // Multiply
        multiply_by_n(vec, 2);
        // Carry
        perform_carry(vec);
    }

    multiply_by_n(vec, 28433);
    perform_carry(vec);

    for (int j = 9; j >= 0; j--){
        cout << vec[j];
    }
    cout << endl;
    cout << endl;
    // Don't forget to add 1 to the submission ;) 
    return 0;
}


void multiply_by_n(vector<int> &vec, int n){
    for(int i = 0; i < vec.size(); i++){
        vec[i] *= n;
    }
}

void perform_carry(vector<int> &vec){
    for (int i = 0; i < vec.size(); i++){
        if (vec[i] < 10) continue;
        // We need to perform a carry
        vec[i + 1] += (vec[i] / 10); // Dividing by 10 chops off the last digit.
        vec[i] %= 10; // Only keep the last number
    }
}
