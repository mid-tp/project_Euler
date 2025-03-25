#include <iostream>
#include <vector>
#include <fstream>
#include <string>
using namespace std;


// Rewrote the problem with vectors.
// Good to try it out first with arrays
// Apparently with arrays we didn't even 
// need to pass a pointer, as this
// is done automatically apparently.
// I wasn't aware of this when I 
// wrote it at first.

void add_number(vector<int> &vec, string num);
void perform_carry(vector<int> &vec);


int main() {
    vector<int> sum_vec;
    u_int8_t offset = 10;
    // Initialize the files for reading in the text.
    ifstream file("text_inputs/problem13.txt");
    string line; 
    
    bool initialized = false;
    // Loop over the data
    while (getline(file, line)){
        if (!initialized) {
            for (int j=0;j < line.size() + offset;j++){
                sum_vec.push_back(0);
            }
            initialized = true;
        }
        add_number(sum_vec, line);
        perform_carry(sum_vec);
    }   
    cout << endl;
    cout << "The first 10 elements are ";
    bool found = false;
    u_int8_t count = 0;
    for (int i = sum_vec.size() - 1; i >= 0; i--){
        if (sum_vec[i] != 0) found = true;
        if (!found) continue;
        count += 1;
        cout << sum_vec[i] << "";
        if (count == 10) break;

    }
    cout << endl;
    return 0;
}

void add_number(vector<int> &vec, string num){
    for (int i=0; i < num.size(); i++){
        vec[i] += num[num.size() - 1 - i] - '0';
    }
}

void perform_carry(vector<int> &vec){
    for (int i = 0; i < vec.size(); i++){
        if (vec[i] < 10) continue;
        // We need to perform a carry

        // Get the order of the
        vec[i + 1] += (vec[i] / 10); // Dividing by 10 chops off the last digit.
        vec[i] %= 10; // Only keep the last number
    }
}

