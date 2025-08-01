#ifndef HASHMAP_H
#define HASHMAP_H

#include "LinkedList.h"
#include <iostream>

using namespace std;

struct HashNode {
    int key;
    Node* value;
    HashNode* next;

    HashNode(int k, Node* v) : key(k), value(v), next(nullptr) {}
};

class HashMap {
private:
    HashNode** table;
    int capacity;
    int size;

    int hashFunction(int key) const; // Hash function used for calculating the bucket index

public:
    // Constructor and Destructor
    HashMap(int capacity = 10);
    ~HashMap();

    // Methods
    void insert(int key, Node* value); // Inserts a key-value pair
    Node* get(int key) const;          // Retrieves value by key
    void remove(int key);              // Removes a key-value pair
    bool contains(int key) const;      // Checks if a key exists
    int getSize() const;               // Gets the number of elements
    void clear();                      // Clears the whole hash map
};

#endif
