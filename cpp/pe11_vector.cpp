#include <iostream>
#include <fstream>
#include <vector> 
#include <sstream>
#include <assert.h>

using namespace std;

const u_int8_t PROD_LENGTH = 4;


void prod_diagonal_left(vector<vector<int>> &grid, int &i, int &j, int &product, vector<int> &prod_numbers){ 
    product = 1;
    for (u_int8_t k=0; k < PROD_LENGTH; k++){
        if ((i + k) >= 20 || (j - k) <  0) continue;
        product *= grid[i + k][j - k];
        prod_numbers[k] = grid[i + k][j - k];
    }   
}

void prod_diagonal_right(vector<vector<int>> &grid, int &i, int &j, int &product, vector<int> &prod_numbers){ 
    product = 1;
    for (u_int8_t k=0; k < PROD_LENGTH; k++){
        if ((i + k) >= 20 || (j + k) >=  20) continue;
        product *= grid[i + k][j + k];
        prod_numbers[k] = grid[i + k][j + k];
    }   
}

void prod_horizontal(vector<vector<int>> &grid, int &i, int &j, int &product, vector<int> &prod_numbers){ 
    product = 1;
    for (u_int8_t k=0; k < PROD_LENGTH; k++){
        if ((j + k) >= 20) continue; // Make sure we cannot go out of bounds.
        product *= grid[i][j + k];
        prod_numbers[k] = grid[i][j + k];
    }
}

void prod_vertical(vector<vector<int>> &grid, int &i, int &j, int &product, vector<int> &prod_numbers){ 
    product = 1;
    for (u_int8_t k=0; k < PROD_LENGTH; k++){
        if ((i + k) >= 20) continue; // Make sure we cannot go out of bounds.
        product *= grid[i + k][j];
        prod_numbers[k] = grid[i + k][j];
    }
}

void update_max_product(int &max_product, int &product, vector<int> &max_prod_numbers, vector<int> &prod_numbers){
    assert (prod_numbers.size() == PROD_LENGTH); // Make sure that the product length is correct

    if (product > max_product){
        // Update the variables
        max_product = product;
        max_prod_numbers = prod_numbers;
        // Check if the product is stored properly
        cout << "The max prod numbers are    " << endl;
        for(int j = 0; j < max_prod_numbers.size(); j++){
            cout << max_prod_numbers[j] << " == " << prod_numbers[j] << endl;
        }
        cout << endl;

    }    
}

int main(){
    // Define the grid of the right size
    const int SIZE = 20;
    vector<vector<int>> grid;

    // Read in the grid.
    ifstream gridNumbers("text_inputs/problem11.txt"); 
    string line;

    // Read out the grid
    while (getline(gridNumbers, line)){
        vector<int> row;
        stringstream ss(line);
        int num;
        while (ss >> num){
            row.push_back(num);
        }
        grid.push_back(row);
    }


    // Variables to store the maximum product and
    // which variables make that product in.
    int max_product = 0;
    int product = 0;
    vector<int> prod_numbers = vector<int>(4, 0);
    vector<int> max_prod_numbers = vector<int>(4, 0);

    // Compute each possible horizontal and diagonal product.
    for (int i = 0; i < SIZE; i++){
        for(int j=0; j<SIZE;j++){
            if (grid[i][j] < 10) continue; // This is probably true, we can skip everthing with value < 10
            prod_horizontal(grid, i, j, product, prod_numbers);
            update_max_product(max_product, product, max_prod_numbers, prod_numbers);

            prod_vertical(grid, i, j, product, prod_numbers);
            update_max_product(max_product, product, max_prod_numbers, prod_numbers);

            prod_diagonal_right(grid, i, j, product, prod_numbers);
            update_max_product(max_product, product, max_prod_numbers, prod_numbers);

            prod_diagonal_left(grid, i, j, product, prod_numbers);
            update_max_product(max_product, product, max_prod_numbers, prod_numbers);
        }
    }

    // Print the max product.
    // Perhaps also store the 
    cout << endl;
    cout << "Max product is " << max_product << endl;
    cout << "Made out from the numbers ";
    for(int j = 0; j < max_prod_numbers.size();j++){
        cout << max_prod_numbers[j] << " ";
    }
    
    cout << endl;

    return 0;
}

