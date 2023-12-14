// Hash Table with Open Address method (Linear probing)

#include <cassert>
#include <iostream>
#include <string>

// Hash node class template
template <typename K, typename V>
class HashNode {
 public:
  HashNode(const K& key, const V& value) : _key(key), _value(value) {}
  K getKey() const { return _key; }
  V getValue() const { return _value; }
  void setValue(V value) { _value = value; }

 private:
  // key-value pair
  K _key;
  V _value;
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

template <typename K, typename V, size_t tableSize,
          typename F = KeyHash<K, tableSize>>
class HashMap {
 private:
  HashMap(const HashMap& other);
  const HashMap& operator=(const HashMap& other);
  // hash table
  HashNode<K, V>* table[tableSize];
  F hashFunc;

 public:
  HashMap() : table(), hashFunc() {}
  ~HashMap() {
    for (size_t i = 0; i < tableSize; i++) {
      table[i] = NULL;
    }
  }

  void insert(const K& key, const V& value) {
    unsigned long hashValue = hashFunc(key);

    // Linear probing
    while (table[hashValue] != NULL) {
      // If the key already exists, update the value
      if (table[hashValue]->getKey() == key) {
        table[hashValue]->setValue(value);
        return;
      }

      // Move to the next slot
      hashValue = (hashValue + 1) % tableSize;
    }

    // Insert at the empty slot
    table[hashValue] = new HashNode<K, V>(key, value);
  }

  bool search(const K& key, V& value) {
    unsigned long hashValue = hashFunc(key);

    // Linear probing
    while (table[hashValue] != NULL) {
      // If the key is found, return the corresponding value
      if (table[hashValue]->getKey() == key) {
        value = table[hashValue]->getValue();
        return true;
      }

      // Move to the next slot
      hashValue = (hashValue + 1) % tableSize;
    }

    // Key not found
    return false;
  }

  void remove(const K& key) {
    unsigned long hashValue = hashFunc(key);
    HashNode<K, V>* entry = table[hashValue];

    // Linear probing
    while (table[hashValue]->getKey() != key) {
      // If the key is found, mark the slot as empty
      if (table[hashValue]->getKey() == key) {
        table[hashValue] = NULL;  // Set to default node
        return;
      }

      // Move to the next slot
      hashValue = (hashValue + 1) % tableSize;
    }

    delete entry;
  }
};

struct MyKeyHash {
  unsigned long operator()(const int& key) const { return key % 10; }
};

using namespace std;

int main() {
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
