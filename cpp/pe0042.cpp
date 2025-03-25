#include "pe_helpers.h"


int main(){

    vector<string> names;

    ifstream file("text_inputs/problem42.txt");
    string line, name; 
    while (getline(file, line)){
        // cout << line;
        stringstream ss(line);
        while (getline(ss, name, ',')){
            names.push_back(name);
        }
    }
    int total = 0, name_score;
    for (const string& name : names){
        name_score = 0;
        for (const char& c : name){
            name_score += pe_methods::get_char_alphabet_pos(c);
        }
        if (!pe_methods::check_triangular(name_score)) continue;
        total += 1;
    }   
    cout << total;
    cout << endl;
    return 0;
}