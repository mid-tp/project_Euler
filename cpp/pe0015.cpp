#include <iostream>
#include <cmath>

using namespace std;

// Lattice paths
// Time to use recursion? 

const int GRID_SIZE = 20;

int main(){
    long long int grid[GRID_SIZE + 1][GRID_SIZE + 1] = {0};



    // Initialize the first row and col
    // There is only one way to reach these cells

    // Fill the first column 
    for(int i=0; i < GRID_SIZE + 1; i++){
        grid[i][0] = 1;
    } 
    // Fill the first row
    for(int j=0; j < GRID_SIZE + 1; j++){
        grid[0][j] = 1;
    } 


    // Fill incrementally...
    for (int r = 1; r < GRID_SIZE + 1; r++){
        for (int c = 1; c < GRID_SIZE + 1; c++){
            grid[r][c] = grid[r-1][c] + grid[r][c - 1];
        }
    }

    // for (int i = 0; i < GRID_SIZE + 1;i++){
    //     cout << endl;
    //     for (int j = 0; j < GRID_SIZE + 1; j++){
    //         cout << grid[i][j] << " ";
    //     }
    // }
    // #if 0

    // #endif


    cout << "Number of paths to reach the bottom right corner is " << grid[GRID_SIZE][GRID_SIZE] << endl;
    return 0;
}