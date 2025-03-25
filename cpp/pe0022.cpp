#include <iostream>
#include <cmath>
#include <fstream>
#include <string>
#include <sstream>
#include <unordered_map>
#include <vector>
#include <algorithm>


using namespace std;

int name_to_score(string name);


int main(){
    vector<string> names;

    ifstream file("text_inputs/problem22.txt");
    string line, name; 
    while (getline(file, line)){
        // cout << line;
        stringstream ss(line);
        while (getline(ss, name, ',')){
            names.push_back(name);
        }
    }


    // Sort the list
    sort(names.begin(), names.end());

    int total_name_score = 0;


    for (int i=0; i < names.size(); i++){
        total_name_score += (i + 1) * name_to_score(names[i]);
        // break;
    }

    cout << total_name_score;


    cout << endl;
    return 0;
}


int name_to_score(string name){
    unordered_map<char, int> letter_to_num = {
        {'A', 1}, {'B', 2}, {'C', 3}, {'D', 4}, {'E', 5}, {'F', 6},
        {'G', 7}, {'H', 8}, {'I', 9}, {'J', 10}, {'K', 11}, {'L', 12},
        {'M', 13}, {'N', 14}, {'O', 15}, {'P', 16}, {'Q', 17}, {'R', 18},
        {'S', 19}, {'T', 20}, {'U', 21}, {'V', 22}, {'W', 23}, {'X', 24},
        {'Y', 25}, {'Z', 26}, {'"', 0}
    };


    int name_score = 0;
    for (char x : name){
        // cout << x << " " << letter_to_num[x] << endl;
        name_score += letter_to_num[x];
    }

    // cout << name << " has score " << name_score << endl;
    return name_score;
}