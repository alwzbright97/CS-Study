#include <iostream>

using namespace std;

class Phone {
 public:
  // 해당 함수를 포인터로 만든다
  virtual void call() {
    cout << "Calling\n";
    return;
  }
};

class SmartPhone : public Phone {
 public:
  // 오버라이드를 명시한다
  void call() override {
    cout << "SmartPhone Calling\n";
    return;
  }
};

int main(int argc, char** argv) {
  Phone phone;
  phone.call();
  SmartPhone smartphone;
  smartphone.call();

  Phone* a = new Phone{};
  // 부모는 자식을 가르킬 수 있다
  Phone* b = new SmartPhone{};
  // 자식은 부모를 가르킬 수 없다
  // SmartPhone* c = new Phone{};
  SmartPhone* d = new SmartPhone{};

  a->call();
  b->call();
  // c->call();
  d->call();

  return 0;
}