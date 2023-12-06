#include <iostream>
#include <list>

using namespace std;

class Coffee {
 private:
  int amount;

 public:
  virtual void drink() = 0;
  virtual void make() = 0;
};

class Person {
 private:
  list<Coffee> coffee_list;

 public:
  void buyOne() {
    // buy a coffee
    return;
  }
  void drinkAll() {
    // drink all of coffee
    return;
  }
};

int main(int argc, char** argv) { return 0; }