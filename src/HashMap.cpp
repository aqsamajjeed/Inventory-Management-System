#include "HashMap.h"

HashMap::HashMap(int capacity) : capacity(capacity), size(0) {
    table = new HashNode*[capacity];
    for (int i = 0; i < capacity; ++i) {
        table[i] = nullptr; // Initializes each bucket to nullptr.
    }
}

// Clear the hash map & delete allocated memory
HashMap::~HashMap() {
    clear();
    delete[] table;
}

// Computation of the hash function
int HashMap::hashFunction(int key) const {
    return key % capacity;
}

// Adds a new key-value pair to the hash map.
void HashMap::insert(int key, Node* value) {
    int bucketIndex = hashFunction(key); // First get the bucket index using the hash function.
    HashNode* newNode = new HashNode(key, value);

    // Insert the new node at the head of the bucket's linked list
    newNode->next = table[bucketIndex];
    table[bucketIndex] = newNode;
    ++size; // Increase the size of the hash map.
}

// Searches for a key and returns its associated value.
Node* HashMap::get(int key) const {
    int bucketIndex = hashFunction(key);
    HashNode* current = table[bucketIndex];

    // Traverse through the entire linked list at the bucket index to find the required key
    while (current) {
        if (current->key == key) {
            return current->value; // Return the associated value if found.
        }
        current = current->next;
    }
    return nullptr; // If key not found.
}

// Deletes a key-value pair from the hash map.
void HashMap::remove(int key) {
    int bucketIndex = hashFunction(key);
    HashNode* current = table[bucketIndex];
    HashNode* prev = nullptr;

    // Traverse through the entire linked list at the bucket index to find the required key
    while (current) {
        if (current->key == key) {
            if (prev) {
                prev->next = current->next; // Bypass the current node
            } else {
                table[bucketIndex] = current->next; // Remove the head node
            }
            delete current; // To free memory
            --size;
            return;
        }
        prev = current;
        current = current->next;
    }
    cout << "Error: Key not found.\n"; // Message if key not found
}

// Will return true if the key is in the hash map, otherwise false
bool HashMap::contains(int key) const {
    return get(key) != nullptr; // Check if the key exists in the hash map
}

// Deletes all nodes in each bucket and resets the size to default
void HashMap::clear() {
    for (int i = 0; i < capacity; ++i) {
        HashNode* current = table[i];
        while (current) {
            HashNode* temp = current;
            current = current->next;
            delete temp; // Delete each node in the linked list
        }
        table[i] = nullptr; // Reset the bucket to nullptr after clearing
    }
    size = 0; // Reset size to 0.
}

// Returns the total number of key-value pairs in the hash map
int HashMap::getSize() const {
    return size;
}
