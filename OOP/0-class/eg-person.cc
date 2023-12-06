#include <iostream>

using namespace std;

class Person {
 public:
  int age;
  int height;
  int weight;
  Person(int height, int weight, int age)
      : height{height}, weight{weight}, age{age} {}
  void print() {
    cout << height << "\n" << weight << "\n" << age << "\n";
    return;
  }
};

int main(int argc, char** argv) {
  Person person1{180, 70, 20};
  person1.print();
  Person* person2_ptr = new Person{180, 70, 20};
  person2_ptr->print();

  return 0;
}