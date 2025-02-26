#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int sum = 0;
    int to_add = 3;
    int factor = 2;

    // 500 because we the size is 1001, so 500 in 'each direction' 
    // from the center element. The example is thus a 2 * 4
    for (int i = 1; i <= 500 * 4; i++){

        cout << "Adding " << to_add << " " << i<< endl;
        sum += to_add;
        if (i % 4 == 0){
            factor += 2;
        }
        to_add += factor;
    }

    cout << "Total is " << sum + 1 << endl;
    return 0;
}