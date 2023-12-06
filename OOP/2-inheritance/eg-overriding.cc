#include <iostream>

using namespace std;

class Phone {
 public:
  void calling() {
    cout << "Calling\n";
    return;
  }
};

class SmartPhone : Phone {
 public:
  void calling() {
    cout << "SmartPhone Calling\n";
    return;
  }
  void internet() {
    cout << "Internet connecting\n";
    return;
  }
};

int main(int argc, char** argv) {
  Phone phone;
  phone.calling();
  SmartPhone smartphone;
  smartphone.calling();
  smartphone.internet();

  return 0;
}