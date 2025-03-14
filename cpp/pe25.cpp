#include <iostream>
#include <vector>
#include <cmath>
using namespace std;




void perform_carry(vector<int> &vec);
void add_vectors(vector<int> &vec1, vector<int> &vec2, vector<int> &vec3);
void print_vec(vector<int> &vec);


int main(){
   vector<int> fib_n2(1001, 0);
   vector<int> fib_n1(1001, 0);
   vector<int> fib_n(1001, 0);

   fib_n2[0] = 1;
   fib_n1[0] = 1;

    int n = 2;
    while (fib_n[999] == 0){
        // We add the previous two fib numbers together.
        add_vectors(fib_n1, fib_n2, fib_n);
        n += 1;
        // Swap
        fib_n2 = fib_n1;
        fib_n1 = fib_n;
        cout << endl << "--------" << endl;
        cout << "n = " << n << " F_n = ";
        print_vec(fib_n);
    }
    // The printing doesn't work anymore, because the integer cannot be stored in an integer. 
    cout << endl;

    return 0;
}

void print_vec(vector<int> &vec){
    bool leading_zeroes = true;
    for (int i = vec.size() - 1; i >= 0; i--){
        if (vec[i] != 0) leading_zeroes = false;
        if (!leading_zeroes) cout << vec[i]; 
    }
}



void add_vectors(vector<int> &vec1, vector<int> &vec2, vector<int> &vec3){
    for (int i=0; i < vec1.size(); i++){
        vec3[i] = (vec2[i] + vec1[i]);
    }
    perform_carry(vec3);
}



void perform_carry(vector<int> &vec){
    for (int i = 0; i < vec.size(); i++){
        if (vec[i] < 10) continue;
        // We need to perform a carry
        vec[i + 1] += (vec[i] / 10);
        while (vec[i] >= 10){
            vec[i] -= 10;
        }
    }
}