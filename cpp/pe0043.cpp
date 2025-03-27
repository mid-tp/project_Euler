#include "pe_helpers.h"

int main()
{
    // Some test number
    constexpr unsigned int number = 1234567890;
    // Convert to string and sort the digits
    string s = to_string(number);
    sort(s.begin(), s.end());
    bool check;
    int n;
    unsigned long int total = 0;
    unsigned long int val;
    vector<int> primes = {2, 3, 5, 7, 11, 13, 17};
    // Work with all permutations
    do {
        check = true;
        n = 0;
        // Check the conditions for sub divisibility
        while (check && n < 7){
            n += 1;
            string subs = s.substr(n, 3);
            val = stoul(subs);
            check = (val % primes[n - 1] == 0);
        }
        if (check && n == 7){
            cout << s << endl;
            val = stoul(s);
            total += val;
        }

    } while (std::next_permutation(s.begin(), s.end()));

    cout << endl << total << endl;
    cout << endl;
}