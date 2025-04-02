#include "pe_helpers.h"

int main(){
    double max_val = -10.0;
    int max_line_number = 0, line_number = 0;;
    // Read in the grid.
    ifstream base_exp("text_inputs/problem99.txt"); 
    vector<int> vec_base_exp;
    string line;
    while (getline(base_exp, line)){
        line_number += 1;
        vec_base_exp.clear();
        stringstream ss(line);
        string val;
        while (getline(ss, val, ',')){
            vec_base_exp.push_back(stoi(val));
        }
        int base = vec_base_exp[0], exp = vec_base_exp[1];
        double val_log = exp * log(base);

        if (val_log > max_val){
            max_val = val_log;
            max_line_number = line_number;
        }
    }
    cout << max_line_number << endl;
    cout << endl;
    return 0;
}
