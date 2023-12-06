#include <iostream>

using namespace std;

class Coffee {
 private:
  int amount;

 public:
  virtual void drink() {
    cout << "Drink Coffee\n";
    return;
  }
};

class Americano : public Coffee {
  void drink() override {
    cout << "Drink Americano\n";
    return;
  }
};

class Latte : public Coffee {
  void drink() override {
    cout << "Drink Latte\n";
    return;
  }
};

class Baristar {
 public:
  Coffee* makeCoffee(int type) {
    if (type == 1) {
      return new Latte();
    }
    if (type == 2) {
      return new Americano();
    }

    return new Coffee();
  }
};

int main(int argc, char** argv) {
  Baristar* baristar = new Baristar();
  Coffee* coffee_1 = baristar->makeCoffee(1);
  Coffee* coffee_2 = baristar->makeCoffee(2);

  coffee_1->drink();
  coffee_2->drink();

  return 0;
}