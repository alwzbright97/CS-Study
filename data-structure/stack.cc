#include <iostream>

template <typename T>
class Node {
 public:
  T data;
  Node* next;

  Node(const T& item) : data(item), next(nullptr) {}
};

// Stack class
template <typename T>
class Stack {
 private:
  Node<T>* top;

 public:
  Stack() : top(nullptr) {}
  ~Stack() {
    while (!isEmpty()) {
      pop();
    }
  }

  bool isEmpty() const { return top == nullptr; }

  void push(const T& item) {
    Node<T>* newNode = new Node<T>(item);
    newNode->next = top;
    top = newNode;
  }

  bool pop() {
    if (isEmpty()) {
      std::cerr << "Stack is empty. Cannot pop." << std::endl;
      return false;
    }

    Node<T>* temp = top;
    top = top->next;
    delete temp;

    return true;
  }

  T peek() const {
    if (isEmpty()) {
      std::cerr << "Stack is empty. Cannot peek." << std::endl;
      throw std::out_of_range("Stack is empty.");
    }

    return top->data;
  }

  void display() const {
    Node<T>* current = top;
    while (current != nullptr) {
      std::cout << current->data << " ";
      current = current->next;
    }
    std::cout << std::endl;
  }
};

int main(int argc, char** argv) {
  // Example usage of Stack
  Stack<int> stack;

  // Push elements in the Stack
  stack.push(1);
  stack.push(2);
  stack.push(3);

  // Display contents of Stack
  std::cout << "Stack contents: ";
  stack.display();

  // Pop element in the Stack
  stack.pop();

  // Display again
  std::cout << "Stack contents: ";
  stack.display();

  std::cout << "Front element of stack: " << stack.peek() << std::endl;

  std::cout << "Check is empty?: " << stack.isEmpty() << std::endl;
  stack.pop();
  stack.pop();
  std::cout << "Check is empty?: " << stack.isEmpty() << std::endl;

  return 0;
}