#include "pe_helpers.h"


int find_right_angle_sols(int p){
    // a^2 + b^2 = c^2
    // a + b + c = p
    unordered_set<int> seen_c;
    int a, num_sols = 0;
    for (int c = 1; c < p; c++){
        for (int b = 1; b < p - c; b++){
            a = p - b - c;
            if (seen_c.count(c) > 0) continue;
            if (a * a + b * b != c * c) continue;
            // cout << a << " " << b << " " << c << endl;
            num_sols += 1;
            seen_c.insert(c);
        }
    }
    // if (num_sols > 0){
    //     cout << num_sols << endl;
    //     cout << endl;
    // }
    return num_sols;
}

int main(){
    int max_sols = 0;
    int num_sols, max_p;
    for (int p = 10; p <= 1000; p ++){
        num_sols = find_right_angle_sols(p);
        if (num_sols > max_sols){
            cout << "p = " << p << " has " << num_sols << " solutions." << endl;
            max_sols = num_sols;
            max_p = p;
        }
    }
    cout << max_p << endl;
    cout << endl;

    return 0;

}