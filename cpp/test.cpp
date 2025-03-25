#include "pe_helpers.h"

using namespace std;

int main() {
  int x = 123;
  
  for (int i = 0; i < 5;i++){
    pe_methods::rotate(x);
    cout << x << endl;
  }
  cout << endl;
}

