#include <iostream>
#include <cmath>
#include "pe_helpers.h"
using namespace std;


int main() {
    int n = 123;
    int n_rev = pe_helpers::reverse(n);  // Call the function
    cout << n_rev << endl;
    return 0;
}