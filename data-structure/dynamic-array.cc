#include <iostream>

template <typename T>
class DynamicArray {
 private:
  T* _data = nullptr;
  int _size = 0;
  int _capacity = 0;

 public:
  DynamicArray() {}
  ~DynamicArray() {
    if (_data) delete[] _data;
  }

  void push_back(const T& value) {
    if (_size == _capacity) {
      int newCapacity = static_cast<int>(_capacity * 1.5);
      if (newCapacity == _capacity) newCapacity++;

      reserve(newCapacity);
    }

    _data[_size] = value;
    _size++;
  }

  void reserve(int capacity) {
    if (_capacity >= capacity) return;
    _capacity = capacity;
    T* newData = new T[_capacity];

    for (int i = 0; i < _size; i++) newData[i] = _data[i];

    delete[] _data;

    _data = newData;
  }

  void clear() {
    if (_data) {
      delete[] _data;
      _data = new T[_capacity];
    }

    _size = 0;
  }

  T& operator[](const int pos) { return _data[pos]; }
  int size() { return _size; }
  int capacity() { return _capacity; }
};

int main(int argc, char** argv) {
  DynamicArray<int> darray;
  std::cout << "size: " << darray.size() << "\n";
  std::cout << "capacity: " << darray.capacity() << "\n";
  darray.push_back(1);
  std::cout << "size: " << darray.size() << "\n";
  std::cout << "capacity: " << darray.capacity() << "\n";
  darray.push_back(2);
  darray.push_back(3);
  darray.push_back(4);
  darray.push_back(8);
  std::cout << "darray\n";
  for (int i = 0; i < darray.size(); i++) {
    std::cout << darray[i] << " ";
  }
  std::cout << "\n";
  std::cout << "size: " << darray.size() << "\n";
  std::cout << "capacity: " << darray.capacity() << "\n";

  return 0;
}