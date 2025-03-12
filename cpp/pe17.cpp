#include <iostream>
#include <cmath>
#include <vector>
#include <unordered_map>
#include <assert.h>
using namespace std;


int num_to_letter_less_hundred(int n, unordered_map<int, int> &single, unordered_map<int, int> &tens, unordered_map<int, int> &ten_and_twenty){
    if (n == 0){
        return -3; // to balance the added "and"
    }
    assert (n < 100);

    if (10 < n  && n < 20){
        return ten_and_twenty[n];
    } 
    int last_digit = n % 10;
    n -= last_digit; // ensure we have 10, 20, 30, etc.
    return tens[n] + single[last_digit];
}

int num_to_letter_count(int n, unordered_map<int, int> &single, unordered_map<int, int> &tens, unordered_map<int, int> &ten_and_twenty){
    if (n < 10){
        return single[n];
    }
    else if (n < 100){
        return num_to_letter_less_hundred(n, single, tens, ten_and_twenty);
    }
    // In this case, n should be >= 100.
    assert (n >= 100);
    // "length" of hundred
    int len_hundred = 7;
    // "length" of and
    int len_and = 3;
    // Get the last digits, subtract to get the 'hundred' part.
    // Then compute how many characaters are in the 'tens' part.
    int last_digits = n % 100;
    int hundred_digit = (n - last_digits) / 100;
    return single[hundred_digit] + len_hundred + len_and + num_to_letter_less_hundred(last_digits, single, tens, ten_and_twenty);
}

int main(){
    // The elements are indexed from value to the number of letters
    //                                one       two     three  four   five     six     seven   eight   nine 
    unordered_map<int, int> single = {{0, 0}, {1, 3}, {2, 3}, {3, 5}, {4, 4}, {5, 4}, {6, 3}, {7, 5}, {8, 5}, {9, 4}};

    // didn't consider,                      eleven,  twelve,    thirteen  fourteen  fifteen  sixteen    seventeen  eighteen, nineteen 
    unordered_map<int, int> ten_and_twenty = {{11, 6}, {12, 6},  {13, 8},  {14, 8},  {15, 7}, {16, 7},   {17, 9},  {18, 8},  {19, 8}};
    // Similarly for the tens
    //                               ten      twenty   thirty   forty    fifty      sixty   seventy  eighty   ninety 
    unordered_map<int, int> tens = {{10, 3}, {20, 6}, {30, 6}, {40, 5}, {50, 5}, {60, 5}, {70, 7}, {80, 6}, {90, 6}};
    
    int letter_count = 0;

    for (int i = 1; i < 1000; i++){
        int temp = num_to_letter_count(i, single, tens, ten_and_twenty);
        cout << "The letter " << i << " has " << temp << " letters." << endl;
        letter_count += temp;
    }
    // // Add one thousand manually, which has 11 characters
    letter_count += 11;

    cout << "Total letter count" << endl;
    cout << letter_count << endl;
    cout << endl;
    return 0;
}