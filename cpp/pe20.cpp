#include <iostream>
#include <cmath>
#include <vector>


using namespace std;


void multiply_by_n(vector<int> &vec, int &n){
    for(int i = 0; i < vec.size(); i++){
        vec[i] *= n;
    }
}


void perform_carry(vector<int> &vec){
    for (int i = 0; i < vec.size(); i++){
        if (vec[i] < 10) continue;
        // We need to perform a carry
        vec[i + 1] += (vec[i] / 10);
        while (vec[i] >= 10){
            vec[i] -= 10;
        }
    }
}



int main(){
    // Probably 500 digits is enough
    // After doing this, look at problem 20, very similar.


    vector<int> vec_factorial = vector(200, 0);
    vec_factorial[0] = 1;

    for(int j = 1; j <= 100; j++){
        multiply_by_n(vec_factorial, j);
        perform_carry(vec_factorial);
    }

    int digit_sum = 0;
    for (auto x : vec_factorial){
        cout << "digit " << x << endl;
        digit_sum += x;
    }

    cout << endl << "Digit sum is " << digit_sum << endl;
    return 0;
}