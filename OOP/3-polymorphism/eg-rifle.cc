#include <iostream>

using namespace std;

class Rifle {
 public:
  virtual void shot() {
    cout << "Rifle\n";
    return;
  }
};

class Shotgun : public Rifle {
 public:
  void shot() override {
    cout << "Shotgun\n";
    return;
  }
};
class Sniper : public Rifle {
 public:
  void shot() override {
    cout << "Sniper\n";
    return;
  }
};

int main(int argc, char** argv) {
  Rifle* a = new Rifle{};
  Rifle* b = new Shotgun{};
  Rifle* c = new Sniper{};

  a->shot();
  b->shot();
  c->shot();

  return 0;
}