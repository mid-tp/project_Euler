#include <iostream>
#include <fstream>
#include <string>
using namespace std;



void add_number(int (*arr)[60], string num);
void perform_carry(int (*arr)[60]);


int main(){
    // We sum 50 digit numbers, so probably 60 digits will be enough

    // Initialize with all zeroes
   int arr_values[60] = {0};
   int (*ptr_arr)[60]= &arr_values; // Create a pointer to the array 

   // Initialize the files for reading in the text.
   ifstream file("text_inputs/problem13.txt");
   string line;

   // Loop over the data
    while (getline(file, line)){
        add_number(ptr_arr, line);
        perform_carry(ptr_arr);
    }
    cout << "The sum of the numbers is ";
    bool found = false;
    for (int j=59; j >= 0; j--){
        if (arr_values[j] != 0) found = true;
        if (!found) continue;
        cout << arr_values[j] << "";
    }
    cout << endl;
    
    cout << endl << "The first 10 digits are ";
    found = false;
    int count = 0;
    for (int j=59; j >= 0; j--){
        if (arr_values[j] != 0) found = true;
        if (!found) continue;
        cout << arr_values[j] << "";
        count ++;
        if (count == 10) break;
    }
    cout << endl;
    return 0;
}

void add_number(int (*arr)[60], string num){
    for (int i = 0; i < 50; i++){
        (*arr)[i] += num[49 - i] - '0';
    }
}

void perform_carry(int (*arr)[60]){
    for (int i = 0; i < 60 - 1; i++){
        if ((*arr)[i] < 10) continue;
        // We need to perform a carry
        // Add the carry
        (*arr)[i + 1] += ((*arr)[i] / 10);
        // Decrease the current value by 10
        (*arr)[i] -= 10;
    }
}

