#include "pe_helpers.h"


long long get_hexagonal(int n){
    long long hex = n * (3 * n - 1) / 2;
    return hex;
}

int main(){
    int n_max = 3000;
    long long hex_i, hex_j, diff, add, min_diff;
    for (int i = 1; i < n_max; i++){
        hex_i = get_hexagonal(i);
        for (int j = 1; j < i; j++){
            hex_j = get_hexagonal(j);
            diff = abs(hex_j - hex_i);
            add = hex_j + hex_i;
            if (!pe_methods::check_pentagonal(diff)) continue;
            if (!pe_methods::check_pentagonal(add)) continue;
            if (diff < min_diff) min_diff = diff;
            cout << i << " " << j << endl;
        }
    }

    cout << min_diff;
    cout << endl;

    return 0;
}

