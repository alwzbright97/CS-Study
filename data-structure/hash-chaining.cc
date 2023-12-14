// Hash Table with Seperate Chaining method

#include <cassert>
#include <iostream>
#include <string>

// Hash node class template
template <typename K, typename V>
class HashNode {
 public:
  HashNode(const K& key, const V& value)
      : _key(key), _value(value), _next(nullptr) {}
  K getKey() const { return _key; }
  V getValue() const { return _value; }
  void setValue(V value) { _value = value; }
  HashNode* getNext() const { return _next; }
  void setNext(HashNode* next) { _next = next; }

 private:
  // key-value pair
  K _key;
  V _value;
  // next bucket with the same key
  HashNode* _next;
  // display copy and assignment
  HashNode(const HashNode&);
  HashNode& operator=(const HashNode&);
};

// Default hash function class
template <typename K, size_t tableSize>
struct KeyHash {
  unsigned long operator()(const K& key) const {
    return reinterpret_cast<unsigned long>(key) % tableSize;
  }
};

// Hash map class template
template <typename K, typename V, size_t tableSize,
          typename F = KeyHash<K, tableSize>>
class HashMap {
 public:
  HashMap() : table(), hashFunc() {}
  ~HashMap() {
    // destroy all buckets one by one
    for (size_t i = 0; i < tableSize; i++) {
      HashNode<K, V>* entry = table[i];

      while (entry != NULL) {
        HashNode<K, V>* prev = entry;
        entry = entry->getNext();
        delete prev;
      }

      table[i] = NULL;
    }
  }

  bool search(const K& key, V& value) {
    unsigned long hashValue = hashFunc(key);
    HashNode<K, V>* entry = table[hashValue];

    while (entry != NULL) {
      if (entry->getKey() == key) {
        value = entry->getValue();
        return true;
      }

      entry = entry->getNext();
    }
    return false;
  }

  void insert(const K& key, const V& value) {
    unsigned long hashValue = hashFunc(key);
    HashNode<K, V>* prev = NULL;
    HashNode<K, V>* entry = table[hashValue];

    while (entry != NULL && entry->getKey() != key) {
      prev = entry;
      entry = entry->getNext();
    }

    if (entry == NULL) {
      entry = new HashNode<K, V>(key, value);

      if (prev == NULL) {
        // insert as first bucket
        table[hashValue] = entry;
      } else {
        prev->setNext(entry);
      }
    } else {
      // just update the value
      entry->setValue(value);
    }
  }

  void remove(const K& key) {
    unsigned long hashValue = hashFunc(key);
    HashNode<K, V>* prev = NULL;
    HashNode<K, V>* entry = table[hashValue];

    while (entry != NULL && entry->getKey() != key) {
      prev = entry;
      entry = entry->getNext();
    }

    if (entry == NULL) {
      // key not found
      return;
    } else {
      if (prev == NULL) {
        // remove first bucket of the list
        table[hashValue] = entry->getNext();
      } else {
        prev->setNext(entry->getNext());
      }

      delete entry;
    }
  }

 private:
  HashMap(const HashMap& other);
  const HashMap& operator=(const HashMap& other);
  // hash table
  HashNode<K, V>* table[tableSize];
  F hashFunc;
};

struct MyKeyHash {
  unsigned long operator()(const int& k) const { return k % 10; }
};

using namespace std;

int main(int argc, char** argv) {
  HashMap<int, string, 10, MyKeyHash> hmap;

  // Insert key-value pairs
  hmap.insert(1, "1");
  hmap.insert(2, "2");
  hmap.insert(3, "3");

  string value;
  bool result;

  // Search for keys
  result = hmap.search(2, value);
  assert(result);
  assert(value == "2");
  cout << value << "\n";

  result = hmap.search(3, value);
  assert(result);
  assert(value == "3");
  cout << value << "\n";

  // Remove a key
  hmap.remove(3);

  // Search again after removal
  result = hmap.search(3, value);
  assert(!result);

  return 0;
}
