#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int a = 13212;
    int b = 99999;
    bool c = true;
    int *ptr_a = &a;
    int *ptr_b = &b;
    bool *ptr_c = &c;
    cout << "Address of a: &a                                 " << &a << endl;
    cout << "Address of b: &b                                 " << &b << endl;
    cout << "Address of c: &c                                 " << &c << endl << endl;

    cout << "Value of: ptr_a                                  " << ptr_a << endl;
    cout << "Value of: ptr_b                                  " << ptr_b << endl;
    cout << "Value of: ptr_c                                  " << ptr_c << endl << endl;

    cout << "Actually pointing to data using a pointer, using the * is called dereferencing: " << endl <<  endl;
    cout << "To what value is the pointer pointing to: *ptr_a " << *ptr_a << endl;
    cout << "To what value is the pointer pointing to: *ptr_b " << *ptr_b << endl;
    cout << "To what value is the pointer pointing to: *ptr_c " << *ptr_c << endl << endl;


    cout << "a                                                " << a << endl;
    cout << "b                                                " << b << endl;
    cout << "c                                                " << c << endl;



    return 0;
}