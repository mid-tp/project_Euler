#include <iostream>
#include <fstream>

using namespace std;

const u_int8_t PROD_LENGTH = 4;


void prod_diagonal_left(int (*grid)[20][20], int i, int j, int &product, int (*prod_numbers)[4]){
    product = 1;
    for (u_int8_t k=0; k < PROD_LENGTH; k++){
        if ((i + k) >= 20 || (j - k) <  0) continue;
        product *= (*grid)[i + k][j - k];
        (*prod_numbers)[k] = (*grid)[i + k][j - k];
    }   
}

void prod_diagonal_right(int (*grid)[20][20], int i, int j, int &product, int (*prod_numbers)[4]){
    product = 1;
    for (u_int8_t k=0; k < PROD_LENGTH; k++){
        if ((i + k) >= 20 || (j + k) >=  20) continue;
        product *= (*grid)[i + k][j + k];
        (*prod_numbers)[k] = (*grid)[i + k][j + k];
    }   
}

void prod_horizontal(int (*grid)[20][20], int i, int j, int &product, int (*prod_numbers)[4]){
    product = 1;
    for (u_int8_t k=0; k < PROD_LENGTH; k++){
        if ((j + k) >= 20) continue; // Make sure we cannot go out of bounds.
        product *= (*grid)[i][j + k];
        (*prod_numbers)[k] = (*grid)[i][j + k];
    }
}

void prod_vertical(int (*grid)[20][20], int i, int j, int &product, int (*prod_numbers)[4]){
    product = 1;
    for (u_int8_t k=0; k < PROD_LENGTH; k++){
        if ((i + k) >= 20) continue; // Make sure we cannot go out of bounds.
        product *= (*grid)[i + k][j];
        (*prod_numbers)[k] = (*grid)[i + k][j];
    }
}

void update_max_product(int &max_product, int &product, int (*max_prod_numbers)[4] ,int (*prod_numbers)[4]){
    if (product > max_product){
        max_product = product;
        for(int m=0;m<4;m++){
            (*max_prod_numbers)[m] = (*prod_numbers)[m];
        }
    }
}

int main(){
    // Define the grid of the right size
    const int SIZE = 20;
    int grid[SIZE][SIZE];

    // Read in the grid.
    ifstream gridNumbers("text_inputs/problem11.txt"); 
    for (int i = 0; i < SIZE; i++){
        for (int j = 0; j < SIZE; j++){
            gridNumbers >> grid[i][j];
        }
    }
    gridNumbers.close();
    // So that we can just give the methods the pointer and 
    // the values of the highest prod will be updated.
    // No need to return it etc. etc.
    int (*ptr_grid)[SIZE][SIZE] = &grid;
    int prod_numbers[4];
    int (*ptr_prod_numbers)[4] = &prod_numbers;

    // Variables to store the maximum in
    int max_product = 0;
    int max_prod_numbers[4] = {0};
    int (*ptr_max_prod_numbers)[4] = &max_prod_numbers;
    int product = 0;

    // Compute each possible horizontal and diagonal product.
    for (int i = 0; i < SIZE; i++){
        for(int j=0; j<SIZE;j++){
            prod_horizontal(ptr_grid, i, j, product, ptr_prod_numbers);
            update_max_product(max_product, product, ptr_max_prod_numbers, ptr_prod_numbers);

            prod_vertical(ptr_grid, i, j, product, ptr_prod_numbers);
            update_max_product(max_product, product, ptr_max_prod_numbers, ptr_prod_numbers);

            prod_diagonal_right(ptr_grid, i, j, product, ptr_prod_numbers);
            update_max_product(max_product, product, ptr_max_prod_numbers, ptr_prod_numbers);

            prod_diagonal_left(ptr_grid, i, j, product, ptr_prod_numbers);
            update_max_product(max_product, product, ptr_max_prod_numbers, ptr_prod_numbers);
        }
    }

    // Print the max product.
    // Perhaps also store the 
    cout << endl;
    cout << "Max product is " << max_product << endl;
    cout << "Made out from the numbers ";
    for(int x : max_prod_numbers){
        cout << x << " * ";
    }
    cout << endl;

    return 0;
}

