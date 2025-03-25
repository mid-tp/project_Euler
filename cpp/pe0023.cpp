#include <iostream>
#include <cmath>
#include <unordered_set>
#include <vector>

using namespace std;


bool check_perfect(int n){

    int16_t total = 0;
    // cout << "Checking if " << n << " is perfect" << endl;
    for (int i = 2; i <= sqrt(n); i++){
        if (!(n % i)){
            total += i;
            total += n / i;
        } 
    }

    return (n - 1) == (total);
}

bool is_abundant(int n){
    int16_t total = 0;
    for (int i = 2; i <= sqrt(n); i++){
        if (!(n % i)){
            total += i;
            if (i == sqrt(n)) continue;
            total += n / i;
        } 
    }
    return (n - 1) < (total);
}


int main(){
    int16_t upper_limit = 28123;
    // Create a list of abundant numbers. Then check for each 
    unordered_set<int> set_abundant_numbers = {};
    vector<int> abundant_numbers = {};
    for (int j = 1; j < 28123; j++){
        if (is_abundant(j)){
         set_abundant_numbers.insert(j);
         abundant_numbers.push_back(j);
        }
    }
    // cannot be written
    bool flag = false;
    int not_abundant_sum = 0;
    // Check if each element can be written as a sum of two abundant numbers
    for (int j=1; j < upper_limit; j++){
        flag = false;
        for (int abundant_num : abundant_numbers){
            u_int32_t diff = j - abundant_num;
            if (diff < 0) break;
            if (set_abundant_numbers.find(diff) != set_abundant_numbers.end()){
                // cout << j << " can be written as the sum of two abundant numbers" << endl;
                flag = true;
                break;
            }
        }
        // We want to sum if the element j CANNOT be 
        // written as a sum of two abundant numbers.
        // If the flag is true, we CAN write it as
        // a sum, so we continue on this case
        if (flag) continue;
        not_abundant_sum += j;
    }
    cout << "The total sum of elements that cannot be written as the sum of two abundant numbers is " << not_abundant_sum << endl;
    cout << endl;
    return 0;
}