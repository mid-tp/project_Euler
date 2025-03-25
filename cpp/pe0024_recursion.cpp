#include <iostream>
#include <vector>
#include <algorithm>
#include <string>


using namespace std;

// This time we list each option, sort the list and index the 1 mil-th element.

int factorial(int n);

int main(){



    cout << endl;
    return 0;
}

int factorial(int n){
    if (n == 1){
        return 1;
    }
    return n * factorial(n - 1);
}
