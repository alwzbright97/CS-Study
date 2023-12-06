#include <iostream>
#include <list>
#include <vector>

using namespace std;

void bubbleSort(vector<int>& arr) {
  cout << "bubble Sort\n";
  for (int i = 0; i < arr.size(); i++) {
    for (int j = i + 1; j < arr.size(); j++) {
      if (arr[i] > arr[j]) {
        swap(arr[i], arr[j]);
      }
    }
  }

  return;
}

void selectionSort(vector<int>& arr) {
  cout << "Selection Sort\n";
  for (int i = 0; i < arr.size(); i++) {
    int minimum = i;

    for (int j = i + 1; j < arr.size(); j++) {
      if (arr[j] < arr[minimum]) minimum = j;
    }
    swap(arr[i], arr[minimum]);
  }

  return;
}

class SortPrinter {
 private:
  vector<int> array;
  void (*sort_func)(vector<int>&);
  void show() {
    cout << "Array Size: " << array.size() << "\n"
         << "Member\n";

    for (int i = 0; i < array.size(); i++) {
      cout << array[i] << " ";
    }
    cout << "\n";

    return;
  }

 public:
  void insert(int num) {
    array.push_back(num);
    return;
  }
  void select(int type_num) {
    if (type_num == 1) {
      sort_func = &bubbleSort;
    }
    if (type_num == 2) {
      sort_func = &selectionSort;
    }

    return;
  }

  void run() {
    cout << "Begin Sort\n";
    show();
    sort_func(array);
    cout << "Finish Sort\n";
    show();
  };
};

int main(int argc, char** argv) {
  SortPrinter sp;

  sp.insert(2);
  sp.insert(3);
  sp.insert(6);
  sp.insert(1);
  sp.insert(4);
  sp.insert(5);

  sp.select(2);
  sp.run();

  return 0;
}