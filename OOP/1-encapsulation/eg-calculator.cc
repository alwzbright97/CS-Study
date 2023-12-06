#include <iostream>

using namespace std;

class Calculator {
 public:
  int result;

  void plus(int a, int b) {
    this->result = a + b;
    return;
  }

  void minus(int a, int b) {
    this->result = a - b;
    return;
  }

  void divide(int a, int b) {
    this->result = a / b;
    return;
  }

  void multiply(int a, int b) {
    this->result = a * b;
    return;
  }

  void printResult() {
    cout << this->result << "\n";
    return;
  }
};

int main(int argc, char** argv) {
  Calculator calc{};
  calc.plus(1, 4);
  calc.printResult();
  calc.minus(1, 4);
  calc.printResult();
  calc.divide(1, 4);
  calc.printResult();
  calc.multiply(1, 4);
  calc.printResult();

  return 0;
}