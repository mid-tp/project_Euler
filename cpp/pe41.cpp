#include "pe_helpers.h"


// Note that most digit sums are divisible by 3
// since their digits are divisible by 3. The highest
// numbers that are not divisible by 3 are 7 digits 
// numbers. The sum of the digits is 
// (7*8)/2 = 28 --> (digit sum) = 10

// Another method would be to list all possible n digital numbers
// loop over them and check which one is prime. Do this for later, good practice
int main(){
    for (int j = 9999999; j >= 100000; j--){
        if (!pe_methods::check_n_digital(j)) continue;
        if (pe_methods::check_prime(j)){
            cout << j << endl;
            break;
        } 
    }
    return 0;
}