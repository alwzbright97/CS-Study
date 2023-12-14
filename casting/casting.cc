#include <iostream>

using namespace std;

class Water {
 public:
  Water(int mL) : mL(mL) {}
  virtual void showInfo() { cout << "mL" << mL << "\n"; }

 private:
  int mL;
};

class SparklingWater : public Water {
 public:
  SparklingWater(int mL, int pH) : Water(mL), pH(pH) {}
  virtual void showInfo() override {
    Water::showInfo();
    cout << "pH" << pH << "\n";
  }

 private:
  int pH;
};

int main(int argc, char** argv) {
  Water* water1 = new SparklingWater(150, 15);
  SparklingWater* sparkling_water_1 = dynamic_cast<SparklingWater*>(water1);
  sparkling_water_1->showInfo();

  /*
  Water* water2 = new Water(150);
  SparklingWater* sparkling_water_2 = static_cast<SparklingWater*>(water2);
  sparkling_water_2->showInfo();
  */

  SparklingWater* sparkling_water_3 = new SparklingWater(150, 20);
  Water* water_3 = dynamic_cast<Water*>(sparkling_water_3);
  water_3->showInfo();

  return 0;
}