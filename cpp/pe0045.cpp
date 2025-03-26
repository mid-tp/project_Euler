#include "pe_helpers.h"

using namespace std;

int get_hexagonal(int n){
    return n * (2 * n - 1);
}

int main() {
    int n = 144;
    long long hexa = get_hexagonal(n);
    bool done = false;
    while (!done){
        hexa = get_hexagonal(n);
        if (pe_methods::check_triangular(hexa) && pe_methods::check_pentagonal(hexa)) done = true;
        n += 1;
    }
    cout << hexa;
    cout << endl;

}

