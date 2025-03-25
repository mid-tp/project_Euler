#include <iostream>
#include <cmath>

using namespace std;


int main(){
    int n = 100;
    int sum_square = pow((n * (n + 1)) / 2, 2);
    int total = 0;
    for (u_int8_t i=0; i<=10;i++){
        total += pow(i, 2);
    }
    cout << "Square of total " << sum_square << endl;
    cout << "Total of squre " << total << endl;
    cout << "Diff " << sum_square - total << endl;
    return 0;
}