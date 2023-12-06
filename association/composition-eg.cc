#include <iostream>
#include <list>

using namespace std;

class CPU {
 private:
  int clock;

 public:
  CPU() { cout << "Create CPU\n"; }
  ~CPU() { cout << "Delete CPU\n"; }
  void thinking() {
    cout << "CPU thinking\n";
    return;
  }
};

class Machine {
 private:
  int hp;

 public:
  virtual void on() = 0;
  virtual void off() = 0;
};

class Robot : public Machine {
 private:
  int robot_id;

 public:
  CPU* brain;
  Robot() {
    cout << "Create Robot\n";
    brain = new CPU();
  }
  ~Robot() {
    cout << "Delete Robot\n";
    delete brain;
  }
  void on() override {
    "Robot On\n";
    return;
  }
  void off() override {
    "Robot Off\n";
    return;
  }
  void walk() { return; };
  void sitDown() { return; };
  void standUp() { return; };
};

int main(int argc, char** argv) {
  Robot* robot = new Robot();
  robot->on();
  robot->off();
  robot->brain->thinking();

  delete robot;

  return 0;
}