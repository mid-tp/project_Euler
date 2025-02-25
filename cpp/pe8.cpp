#include <iostream>
#include <vector>
#include <fstream>
#include <string>
using namespace std;



void add_number(int* arr, string num);
void perform_carry(int);


int main(){
    // We sum 50 digit numbers, so probably 60 digits will be enough

    // Initialize the files for reading in the text.
    ifstream gridNumbers("text_inputs/problem8.txt");
    string line;
    // Be aware, we need a 64 bit int to store the number
    // A regular int doesn't do the job, because it is
    // too big to store it in only 32 bits.
    u_int64_t product;
    u_int64_t max_product = 0;

    
    vector<u_int8_t> prod_numbers;
    vector<u_int8_t> max_prod_numbers;
    vector<int> grid_numbers;

    while (getline(gridNumbers, line)){
        for (char c : line){
            grid_numbers.push_back(c - '0');
        }
    }

    #if 0
    for(auto x : grid_numbers) cout << x;
    #endif

    #if 1
    u_int8_t prod_length = 13;

    for (int i = 0; i < grid_numbers.size() - prod_length; i++){
        prod_numbers.clear();
        product = 1;
        for (int j = 0; j < prod_length; j++){
            product *= grid_numbers[i + j];
            prod_numbers.push_back(grid_numbers[i + j]);
        }
        if (product < max_product) continue;
        // We found a bigger product
        max_product = product;
        max_prod_numbers = prod_numbers;

    }
    cout << "The value of the maximum product is " << endl;
    for (int x : max_prod_numbers) cout << x << " * ";
    cout << " = "<< max_product << endl;
    #endif
    cout << endl;
    return 0;
}