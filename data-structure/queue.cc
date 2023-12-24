#include <iostream>

template <typename T>
class Node {
 public:
  T data;
  Node* next;

  Node(const T& item) : data(item), next(nullptr) {}
};

// Queue class
template <typename T>
class Queue {
 private:
  Node<T>* front;
  Node<T>* rear;

 public:
  Queue() : front(nullptr), rear(nullptr) {}

  ~Queue() {
    while (!isEmpty()) {
      dequeue();
    }
  }

  bool isEmpty() const { return front == nullptr; }

  void enqueue(const T& item) {
    Node<T>* newNode = new Node<T>(item);

    if (isEmpty()) {
      front = rear = newNode;
    } else {
      rear->next = newNode;
      rear = newNode;
    }
  }

  bool dequeue() {
    if (isEmpty()) {
      std::cerr << "Queue is empty. Cannnot dequeue." << std::endl;
      return false;
    }

    Node<T>* temp = front;
    front = front->next;
    delete temp;

    // If dequeuing the last element, update rear
    if (front == nullptr) {
      rear = nullptr;
    }

    return true;
  }

  T peek() const {
    if (isEmpty()) {
      std::cerr << "Queue is empty. Cannot peek." << std::endl;
      throw std::out_of_range("Queue is empty");
    }

    return front->data;
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
  // Example usage of Queue
  Queue<int> queue;

  // Enqueue element in the Queue
  queue.enqueue(1);
  queue.enqueue(2);
  queue.enqueue(3);

  // Display contents of queue
  std::cout << "Queue contents: ";
  queue.display();

  // Dequeue element in the Queue
  queue.dequeue();

  // Display again
  std::cout << "Queue contents: ";
  queue.display();

  // Check first element in the Queue
  std::cout << "Front element of queue: " << queue.peek() << std::endl;

  // Check if the Queue is empty
  std::cout << "Check is empty?: " << queue.isEmpty() << std::endl;

  // Dequeue all of element in the Queue
  queue.dequeue();
  queue.dequeue();

  // Check if the Queue is empty
  std::cout << "Check is empty?: " << queue.isEmpty() << std::endl;

  return 0;
}