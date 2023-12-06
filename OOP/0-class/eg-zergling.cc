#include <iostream>

using namespace std;

class Zergling {
 public:
  int hp = 80;
  int mana = 200;

  void attack() {
    this->hp += 1;
    this->mana -= 10;
    return;
  }

  void move() {
    this->hp -= 10;
    this->mana += 5;
    return;
  }

  void status() {
    cout << "HP   : " << this->hp << "\n";
    cout << "MANA : " << this->mana << "\n";
    return;
  }
};

int main(int argc, char** argv) {
  Zergling zergling_1{};

  zergling_1.attack();
  zergling_1.move();
  zergling_1.status();

  Zergling* zergling_2_ptr = new Zergling{};

  zergling_2_ptr->move();
  zergling_2_ptr->status();
  zergling_2_ptr->attack();
  zergling_2_ptr->status();

  return 0;
}