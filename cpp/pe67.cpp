#include <iostream>
#include <fstream>
#include <vector> 
#include <sstream>
#include <assert.h>

using namespace std;

int main(){

    vector<vector<int>> grid;
    // Read in the grid.
    ifstream gridNumbers("text_inputs/problem67.txt"); 
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

    for (auto row : grid){
        cout << "Length row is " << row.size() << endl;
    }
    
    for (int r=grid.size() - 2; r >= 0; r--){
        for (int c = 0; c < grid[r].size(); c++)
            grid[r][c] += max(grid[r + 1][c], grid[r + 1][c + 1]);
    }

    cout << "The largest value is " << grid[0][0];

    cout << endl;
    return 0;
}