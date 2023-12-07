#include <iostream>

class Node {
 public:
  Node(int value) : _data(value), _next(nullptr), _prev(nullptr) {}
  int _data;
  Node* _next;
  Node* _prev;
};

class DoubleLinkedList {
 private:
  Node* _head = nullptr;
  Node* _tail = nullptr;

 public:
  // [head] <-> [tail]
  DoubleLinkedList() {
    _head = new Node(0);
    _tail = new Node(0);
    _head->_next = _tail;
    _tail->_prev = _head;
  }

  ~DoubleLinkedList() {
    Node* node = _head;

    while (node) {
      Node* deleteNode = node;
      node = node->_next;
      delete deleteNode;
    }
  }

  // [head]<->[1]<->[2]<->...<->[tail]
  Node* GetNode(int index) {
    Node* node = _head->_next;

    if (index < 0 || node == _tail) return nullptr;

    for (int i = 0; i < index; i++) {
      node = node->_next;
    }

    if (node == _tail) return nullptr;

    return node;
  }

  void Print() {
    Node* node = _head->_next;

    while (node != _tail) {
      std::cout << node->_data << " ";
      node = node->_next;
    }
    std::cout << "\n";
  }

  //[head]<->[node]<->[NextNode]<->[tail]
  Node* AddAtHead(int value) {
    Node* node = new Node(value);
    Node* nextNode = _head->_next;

    _head->_next = node;

    node->_prev = _head;
    node->_next = nextNode;

    nextNode->_prev = node;
    return node;
  }

  // [head]<->[prevNode]<->[node]<->[tail]
  Node* AddAtTail(int value) {
    Node* node = new Node(value);
    Node* prevNode = _tail->_prev;

    prevNode->_next = node;

    node->_prev = prevNode;
    node->_next = _tail;

    _tail->_prev = node;

    return node;
  }

  // [head]<->[prevNode]<->[node]<->[posNode]<->[tail]
  Node* Insert(Node* posNode, int value) {
    Node* node = new Node(value);
    Node* prevNode = posNode->_prev;

    prevNode->_next = node;

    node->_prev = prevNode;
    node->_next = posNode;

    posNode->_prev = node;

    return node;
  }

  // [head]<->[prevNode]<->[node]<->[posNode]<->[tail]
  void Delete(Node* node) {
    Node* prevNode = node->_prev;
    Node* nextNode = node->_next;

    prevNode->_next = nextNode;
    nextNode->_prev = prevNode;

    delete node;
  }
};

int main(int argc, char** argv) {
  DoubleLinkedList double_linked_list;
  double_linked_list.AddAtHead(1);
  double_linked_list.AddAtTail(3);
  double_linked_list.AddAtTail(5);
  double_linked_list.AddAtTail(4);
  double_linked_list.AddAtTail(8);
  double_linked_list.Print();

  Node* node_3 = double_linked_list.GetNode(3);
  double_linked_list.Insert(node_3, 7);

  double_linked_list.Delete(node_3);
  double_linked_list.Print();

  // 메모리 누수 확인용
  while (true) {
    DoubleLinkedList dli = DoubleLinkedList();
  }

  return 0;
}