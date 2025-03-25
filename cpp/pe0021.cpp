#include <iostream>
#include <cmath>
#include <unordered_map>
#include <unordered_set>
using namespace std;


int sum_divisors(int n){
    int total = 1;
    // cout << "Checking if " << n << " is perfect" << endl;
    int sqrt_n = sqrt(n);
    for (int i = 2; i <= sqrt_n; i++){
        if ((n % i) == 0){
            total += i;
            if (i == sqrt_n) continue;
            total += n / i;
        } 
    }
    return total;
}

int main(){
    int upper_limit = 10000;
    // Create a list of abundant numbers. Then check for each 
    unordered_map<int, int> num_to_divsum;
   

    for (int i = 1; i < upper_limit; i++){
        num_to_divsum[i] = sum_divisors(i);
    }


    int amicable_sum = 0;
    unordered_set<int> added = {};

    for (int j = 1; j < upper_limit; j++){
        if (added.find(j) != added.end() || j == num_to_divsum[j]) continue; // Don't add amicable numbers twice and skip perfect numbers
        if (num_to_divsum[num_to_divsum[j]] != j) continue; // Check if the pair is amicable.
        cout << "Amicable pair " << j << " and " << num_to_divsum[j] << endl;
        amicable_sum += j;
        amicable_sum += num_to_divsum[j];
        added.insert(j);
        added.insert(num_to_divsum[j]);
    }

    cout << amicable_sum;
    cout << endl;
    return 0;
}





