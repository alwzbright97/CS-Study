#include <iostream>

using namespace std;

int main(int argc, char** argv) {
  int var1;  // uninitialized

  int var2 = 0;  // C-like initialization

  int var3(0);  // Constructor initialization

  int var4{0};  // C++11 list initialization syntax

  cout << var1 << endl << var2 << endl << var3 << endl << var4 << endl;

  return 0;
}