#include <iostream>

using namespace std;
// Interface
class ICamera {
 public:
  virtual void take() = 0;
};

class Camera : public ICamera {
 public:
  void take() {
    cout << "take picture\n";
    return;
  }
};

class HDCamera : public ICamera {
 public:
  void take() {
    cout << "take picture HD\n";
    return;
  }
};

class People {
 public:
  void useCamera(ICamera* p) { p->take(); }
};

int main(int argc, char** argv) {
  People p;
  Camera c1;
  p.useCamera(&c1);

  HDCamera hd;
  p.useCamera(&hd);

  return 0;
}