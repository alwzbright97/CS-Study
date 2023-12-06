#include <iostream>

using namespace std;

class Person {
 public:
  // Member data
  int a;
  int b;
  // Member function, method
  void abc() {
    cout << "Function\n";
    return;
  }
};

int main(int argc, char** argv) {
  Person t{};  // Allocated in Stack
  t.abc();

  Person* t_ptr = new Person{};  // Allocated in Heap
  t_ptr->abc();

  return 0;
}