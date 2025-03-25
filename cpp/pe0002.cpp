#include <iostream>

using namespace std;

int main(){
    int even_total = 0;
    int prev_prev = 1;
    int prev = 2;
    int next = prev;
    while (next < 4000000){
        if (next % 2 == 0){
            even_total += next;
        }
        next = prev_prev + prev;
        prev_prev = prev;
        prev = next;

    }
    cout << "Sum of even Fib terms up to 4 mil is: " << even_total << endl;
}