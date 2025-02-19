#include <iostream>
#include <cmath>
using namespace std;

int main(){
    u_int16_t c;
    u_int16_t sqrt_c;
    bool found = false;
    for(u_int16_t a=1;a<500;a++){
        for (u_int16_t b=a;b<500;b++){
           for (u_int16_t c=b;c<500;c++){
                if (pow(a, 2) + pow(b,2) == pow(c,2) && a + b + c == 1000){
                    cout << "a * b * c = " << a*b*c << endl;
                    cout <<a << " " << b << " " << c <<endl;
                    found = true;
                    continue;
                }            
            }
            if (found){
                continue;
            }
        }
        if (found){
            break;
        }
    }
    return 0;
}

