#include <iostream>

using namespace std;

class Calculator {
 private:
  // In-accessible
  int result;

 public:
  void sum(int a, int b) {
    this->result = a + b;
    return;
  }

  void minus(int a, int b) {
    this->result = a - b;
    return;
  }

  void divide(int a, int b) {
    if (b == 0) {
      cout << "Error\n";
      return;
    }
    this->result = a / b;
    return;
  }

  void multiply(int a, int b) {
    this->result = a * b;
    return;
  }

  int add(int a, int b) {
    int result = 0;
    for (int i = a; i <= b; i++) {
      result += i;
    }
    return result;
  }

  void printResult() {
    cout << this->result << "\n";

    return;
  }
};

int main(int argc, char** argv) {
  Calculator calc{};

  calc.sum(5, 6);
  calc.printResult();

  calc.minus(2, 3);
  calc.printResult();

  calc.divide(24, 0);
  calc.printResult();

  calc.multiply(5, 6);
  calc.printResult();

  return 0;
}