#include <iostream>

template <typename T>
class Node {
 public:
  T data;
  Node* next;

  Node(const T& item) : data(item), next(nullptr) {}
};
template <typename T>
class Deque {
 private:
  Node<T>* front;
  Node<T>* rear;

 public:
  Deque() : front(nullptr), rear(nullptr) {}

  ~Deque() {
    while (!isEmpty()) {
      popFront();
    }
  }

  bool isEmpty() const { return front == nullptr; }

  void pushFront(const T& item) {
    Node<T>* newNode = new Node<T>(item);

    if (isEmpty()) {
      front = rear = newNode;
    } else {
      rear->next = newNode;
      rear = newNode;
    }
  }

  void pushBack(const T& item) {
    Node<T>* newNode = new Node<T>(item);

    if (isEmpty()) {
      front = rear = newNode;
    } else {
      rear->next = newNode;
      rear = newNode;
    }
  }

  bool popFront() {
    if (isEmpty()) {
      std::cerr << "Deque is empty. Cannot pop from front." << std::endl;
      return false;
    }

    Node<T>* temp = front;
    front = front->next;
    delete temp;

    // If popping the last element, update rear
    if (front == nullptr) {
      rear = nullptr;
    }

    return true;
  }

  bool popBack() {
    if (isEmpty()) {
      std::cerr << "Deque is empty. Cannot pop from back." << std::endl;
      return false;
    }

    if (front == rear) {
      // If only one element is present, pop from front.
      return popFront();
    }

    // Find the node before the rear
    Node<T>* temp = front;
    while (temp->next != rear) {
      temp = temp->next;
    }

    delete rear;
    temp->next = nullptr;
    rear = temp;

    return true;
  }

  T peekFront() const {
    if (isEmpty()) {
      std::cerr << "Deque is empty. Cannot peek from front." << std::endl;
      throw std::out_of_range("Deque is empty");
    }

    return front->data;
  }

  T peekBack() const {
    if (isEmpty()) {
      std::cerr << "Deque is empty. Cannot peek from back." << std::endl;
      throw std::out_of_range("Deque is empty");
    }

    return rear->data;
  }

  void display() const {
    Node<T>* current = front;
    while (current != nullptr) {
      std::cout << current->data << " ";
      current = current->next;
    }
    std::cout << std::endl;
  }
};

int main(int argc, char** argv) {
  Deque<int> deque;

  // Push elements onto the front and back of the Deque
  deque.pushFront(1);
  deque.pushFront(2);
  deque.pushBack(3);
  deque.pushBack(4);
  deque.pushFront(5);

  // Display contents of Deque
  std::cout << "Deque contents: ";
  deque.display();

  // Pop element in the Deque
  deque.popFront();
  deque.popBack();

  // Display again
  std::cout << "Deque contents: ";
  deque.display();

  std::cout << "Front element of deque: " << deque.peekFront() << std::endl;
  std::cout << "Back element of deque: " << deque.peekBack() << std::endl;

  std::cout << "Check is empty?: " << deque.isEmpty() << std::endl;
  deque.popFront();
  deque.popFront();
  deque.popBack();
  std::cout << "Check is empty?: " << deque.isEmpty() << std::endl;

  return 0;
}