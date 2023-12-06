#include <iostream>

using namespace std;

class GameMachine {
 private:
  int total_coin;

  void showStatus() {
    cout << "Status\n"
         << "Left coin : " << total_coin << "\n";
    return;
  }

 public:
  GameMachine() {
    this->total_coin = 0;
    showStatus();
  }
  void inputCoin(int n_coin) {
    if (n_coin > 5) {
      cout << "Error : too many coin enterred\n";
      return;
    }

    if (n_coin + this->total_coin > 10) {
      cout << "Error : too many coin enterred\n";
      return;
    }

    this->total_coin += n_coin;
    showStatus();
    return;
  }

  void playGame() {
    if (total_coin < 1) {
      cout << "Error : there is No coin left\n";
      return;
    }

    this->total_coin--;
    showStatus();
    return;
  }
};

int main(int argc, char** argv) {
  GameMachine gm{};
  gm.inputCoin(3);
  gm.playGame();
  gm.inputCoin(5);
  gm.playGame();
  gm.inputCoin(5);
  gm.playGame();
  return 0;
}