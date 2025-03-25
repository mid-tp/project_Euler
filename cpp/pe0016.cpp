#include <iostream>
#include <cmath>
#include <vector>


using namespace std;


void multiply_by_2(vector<int> &vec){
    for(int i = 0; i < vec.size(); i++){
        vec[i] *= 2;
    }

}

void perform_carry(vector<int> &vec){
    for (int i = 0; i < vec.size(); i++){
        if (vec[i] < 10) continue;
        // We need to perform a carry
        vec[i + 1] += (vec[i] / 10);
        vec[i] -= 10;
    }
}



int main(){
    // Probably 500 digits is enough

    // After doing this, look at problem 20, very similar.

    vector<int> digits_power_2 = vector(500, 0);
    digits_power_2[0] = 1;
    for(int j = 0; j < 1000; j++){
        multiply_by_2(digits_power_2);
        perform_carry(digits_power_2);
    }
    int digit_sum = 0;
    for (auto x : digits_power_2){
        cout << "digit " << x << endl;
        digit_sum += x;
    }

    cout << endl << "Digit sum is " << digit_sum << endl;
    return 0;
}