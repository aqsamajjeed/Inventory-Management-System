#include "LinkedList.h"

// Initialization
LinkedList::LinkedList() : head(nullptr), size(0) {}

// Deallocation of all nodes in the linked list
LinkedList::~LinkedList() {
    clear(); // To free up memory.
}

// Adds a new item to the end of the linked list
void LinkedList::append(const Item& item) {
    Node* newNode = new Node(item);
    if (!head) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    size++;
}

// Removes item from the linked list at the wanted index
void LinkedList::remove(int index) {
    if (index < 0 || index >= size) { // Check if index is out of bounds
        cout << "Error: Index out of bounds.\n";
        return;
    }

    Node* temp = head;
    if (index == 0) {
        head = head->next; // If index is 0, remove the head node
        delete temp; // Deallocate the memory for the removed node
    } else {
        for (int i = 0; i < index - 1; ++i) {
            temp = temp->next;
        }
        Node* toDelete = temp->next;
        temp->next = toDelete->next;
        delete toDelete;
    }
    size--;
}

// Returns a pointer/address to the node at the wanted index
Node* LinkedList::getNode(int index) const {
    if (index < 0 || index >= size) { // Check if index is out of bounds
        return nullptr;
    }
    Node* temp = head;
    for (int i = 0; i < index; ++i) {
        temp = temp->next;
    }
    return temp;
}

// Returns a pointer to the head node
Node* LinkedList::getHead() const {
    return head;
}

// Deletes all nodes in the linked list & frees up memory
void LinkedList::clear() {
    Node* temp = head;
    while (temp) {
        Node* next = temp->next;
        delete temp;
        temp = next;
    }
    head = nullptr; // Reset the head to nullptr (shows empty list)
    size = 0; // Set the size to default=0
}

// returns the number of elements in the linked list
int LinkedList::getSize() const {
    return size;
}
