#include <iostream>
using namespace std;

int reverse(int n){
    int reversed = 0;
    int last_digit;
    while (n != 0){
        last_digit = n - 10 * (n / 10);
        n /= 10;
        reversed = 10 * reversed + last_digit;
    }
    return reversed;
}


int main(){
    int n;
    int max_palindrome = 0;
    u_int16_t p1;
    u_int16_t p2;
    for (int i=1;i<1000;i++){
        for (int j=i;j<1000;j++){
            n = i * j;
            if (n == reverse(n)){
                if (n > max_palindrome){
                    max_palindrome = n;
                    // cout << "New max palindrome " << max_palindrome << endl;
                    p1 = i;
                    p2 = j;
                }
            }
        }
    }
    cout << "Highest palindrome as product of two 3-digit numbers: " << endl << max_palindrome << " = " << p1 << " * " << p2 << endl;
    return 0;
}