#include <iostream>

using namespace std;
// Interface
class ISocket {
 public:
  virtual void plugIn() = 0;
  virtual void unPlug() = 0;
};

class Samsung : public ISocket {
 private:
  void enable330V() {
    cout << "enable 330V\n";
    return;
  }

  void disable330V() {
    cout << "disable 330V\n";
    return;
  }

 public:
  void plugIn() override {
    enable330V();
    return;
  }
  void unPlug() override {
    disable330V();
    return;
  }
};
class SunPower : public ISocket {
 private:
  void enableSunPower() {
    cout << "enableSunPower\n";
    return;
  }

  void disableSunPower() {
    cout << "disableSunPower\n";
    return;
  }

 public:
  void plugIn() override {
    enableSunPower();
    return;
  }
  void unPlug() override {
    disableSunPower();
    return;
  }
};

class Dansung : public ISocket {
 private:
  void enable220V() {
    cout << "enable 220V\n";
    return;
  }

  void disable220V() {
    cout << "disable 220V\n";
    return;
  }

 public:
  void plugIn() override {
    enable220V();
    return;
  }
  void unPlug() override {
    disable220V();
    return;
  }
};

void testSocket(ISocket* socket) {
  socket->plugIn();
  socket->unPlug();

  return;
}

int main(int argc, char** argv) {
  Samsung a;
  SunPower b;
  Dansung c;

  testSocket(&a);
  testSocket(&b);
  testSocket(&c);

  return 0;
}