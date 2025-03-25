#include <iostream>
#include <cmath>
#include <unordered_map>
#include <vector>
#include <chrono>
using namespace std;


void performCollatz(u_int64_t &n){
    if ((n % 2) == 0){ //odd
        n /= 2;
    }else{ // even
        n = 3 * n + 1;
    }
}

int main(){
    unordered_map<u_int64_t, int> num_dist; // to keep track of the numbers that we have seen so far, mapped to the length of the sequence up to that point.
    // num_dist.reserve(pow(10, 6));
    vector<u_int64_t> seen; // to store the current sequence in
    // seen.reserve(1000000);
    u_int64_t n = 0;
    int max_length = 0, length = 0, to_add = 0, max_number = 0, seen_size = 0, max_seq_size = 0;
    for(u_int64_t i=1; i < pow(10, 6); i++){
        // cout << endl << "Checking " << i << "..." << endl;
        // Reset the variables
        to_add = 0;
        n = i;
        // Clear the list of elements.
        seen.clear(); // empty the set
        seen.push_back(n); // add where we start.
        while(n!=1){
            // Check if we have seen the element before
            if (num_dist.count(n)){
                // cout << "We break early cur i=" << i << " at number="<< n << endl;
                to_add = num_dist[n];
                break;
            }
            performCollatz(n);
            seen.push_back(n);
        }
        // Store the size of the numbers in the current chain until we hit either
        // the number 1 OR a number that we have seen before, and from which we 
        // have stored the number of steps still to go, in to_add.
        seen_size = seen.size();

        // For every number in the list 'seen' add the length to 'num_dist' that
        // we still have to go to hit the number 1.
        for (int j = seen_size - 1; j >= 0; j--){
            num_dist[seen[j]] = seen_size - 1 - j + to_add;
            //Check if the biggest sequence length is the biggest
            if (seen_size - 1 - j + to_add < max_seq_size) continue;
            max_seq_size = seen_size - 1 - j + to_add;
            max_number = i;
        }
    }
    // for (auto it = num_dist.begin(); it != num_dist.end(); ++it){
    // cout << "Length for  " << 99998 <<  " is " << num_dist[99998] << endl;
    cout << endl << "The number that has the HIGHEST Collatz sequence length below 10^6 is " << max_number << " with length: " << max_seq_size << endl;
    return 0;
}