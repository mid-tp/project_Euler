#include <iostream>
using namespace std;

int main(){
    float avg = 0;
    float arr[] = {1.0, 4.5, 423.43, 2323.0, 54.0};
    for (float val: arr){
        avg += val;
    }
    cout << avg << endl;
    cout << sizeof(arr) << endl;
    cout << avg/5 << endl;


}