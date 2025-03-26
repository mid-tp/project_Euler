#include "pe_helpers.h"

bool check_9_digital(unordered_set<int> s){
    unordered_set<int> check = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    return s == check;
}

int main(){
    unordered_set<int> digits_i, digits_j, digits_prod, added_prods;
    int prod, order_i, order_j, order_prod;
    int total = 0;

    for (int i = 1; i <= 100; i++){
        for (int j = 100; j <= 10000; j++){
            prod = i * j;
            order_i = pe_methods::get_order(i);
            order_j = pe_methods::get_order(j);
            order_prod = pe_methods::get_order(prod);
            if ((order_i + order_j + order_prod) != 6) continue;

            digits_i = pe_methods::get_digit_set(i);
            digits_j = pe_methods::get_digit_set(j);
            unordered_set<int> union_set(digits_i.begin(), digits_i.end());
            union_set.insert(digits_j.begin(), digits_j.end());
            if (added_prods.count(prod) > 0) continue;
            digits_prod = pe_methods::get_digit_set(prod);
            union_set.insert(digits_prod.begin(), digits_prod.end());
            if (!check_9_digital(union_set)) continue;
            added_prods.insert(prod);
            total += prod;
            cout << i << " * " << j << " = " << prod << endl;
        }
    }

    cout << total;
    cout << endl;



}