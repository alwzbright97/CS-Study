#include <iostream>

using namespace std;

class Base {
 public:
  int hp;
  void move() { return; }
  void stop() { return; }

  Base(int hp) : hp{hp} {}
};

class Derived : public Base {
 public:
  int model_id;
  void run() { return; }
  void walk() { return; }

  Derived(int hp, int _model_id) : Base(hp) { model_id = _model_id; }
};

int main(int argc, char** argv) {
  Derived derived_class1{100, 1};

  cout << "hp : " << derived_class1.hp << "\n";
  cout << "model_id : " << derived_class1.model_id << "\n";

  derived_class1.move();
  derived_class1.stop();

  derived_class1.run();
  derived_class1.walk();

  return 0;
}