#include "Inventory.h"
#include <fstream>

// Add a new item to the inventory
void Inventory::addItem() {
    int id;
    string name;
    int quantity;
    double price;

    // Prompt user for item information
    cout << "Enter Item ID: ";
    cin >> id;
        // Check if the item ID already exists in the hash map
        if (itemIndex.contains(id)) {
            cout << "Error: Item ID already exists!\n";
            return;
        }
    cout << "Enter Item Name: ";
    cin >> name;
    cout << "Enter Quantity: ";
    cin >> quantity;
    cout << "Enter Price: ";
    cin >> price;

    // Create new item with the provided info
    Item newItem(id, name, quantity, price);

    // Add the new item to the linked list
    items.append(newItem);

    // Get the newly added node from the linked list
    Node* node = items.getNode(items.getSize() - 1);

    // Insert the node reference into the hash map (used for quick lookup)
    itemIndex.insert(id, node);

    cout << "Item added successfully!\n";
}

// Remove an existing item by ID
void Inventory::removeItem() {
    int id;
    cout << "Enter Item ID to Remove: ";
    cin >> id;

    // Check if the item exists in the hash map
    if (!itemIndex.contains(id)) {
        cout << "Error: Item with ID " << id << " not found.\n";
        return;
    }

    // Get the node pointer from the hash map
    Node* node = itemIndex.get(id);

    // Find the index of the node in the linked list
    Node* currentNode = items.getHead();
    int index = 0;
    while (currentNode != nullptr) {
        if (currentNode == node) {
            break;
        }
        currentNode = currentNode->next;
        index++;
    }

    // Remove the item from the linked list using the index
    if (currentNode != nullptr) {
        items.remove(index); // Remove the item from the linked list
        itemIndex.remove(id); // Remove the item from the hash map
        cout << "Item removed successfully!\n";
    } else {
        cout << "Error: Could not find the node in the list.\n";
    }
}

// Update an existing item by ID
void Inventory::updateItem() {
    int id;
    cout << "Enter Item ID to Update: ";
    cin >> id;

    // Check if the item exists in the hash map
    if (!itemIndex.contains(id)) {
        cout << "Error: Item with ID " << id << " not found.\n";
        return;
    }

    // Get the node pointer from the hash map
    Node* node = itemIndex.get(id);

    // Prompt user for new item details
    cout << "Enter new Name: ";
    string name;
    cin >> name;
    cout << "Enter new Quantity: ";
    int quantity;
    cin >> quantity;
    cout << "Enter new Price: ";
    double price;
    cin >> price;

    // Update the item in the node with new details
    node->data = Item(id, name, quantity, price);

    cout << "Item updated successfully!\n";
}

// Display all items in the inventory
void Inventory::displayItems() const {
    if (items.getSize() == 0) {
        cout << "Inventory is empty!\n";
        return;
    }

    cout << "Inventory Items:\n";
    Node* current = items.getHead();
    while (current) {
        current->data.display();
        current = current->next;
    }
}

// Save the inventory to a file
void Inventory::saveToFile() const {
    ofstream outFile("C:\\Users\\Fame\\Documents\\DSA\\DSA_Project\\Inventory.txt");
    if (!outFile) {
        cout << "Error opening file for writing!\n";
        return;
    }

    // Traverse the linked list and write item details to the file
    Node* current = items.getHead();
    while (current) {
        outFile << current->data.getId() << " "
                << current->data.getName() << " "
                << current->data.getQuantity() << " "
                << current->data.getPrice() << endl;
        current = current->next;
    }

    outFile.close();
    cout << "Data saved successfully to inventory.txt!\n";
}

// Load inventory data from a file
void Inventory::loadFromFile() {
    ifstream inFile("C:\\Users\\Fame\\Documents\\DSA\\DSA_Project\\Inventory.txt");
    if (!inFile) {
        cout << "Error opening file for reading!\n";
        return;
    }

    // Clear the existing inventory and index
    items.clear();
    itemIndex.clear();

    int id, quantity;
    double price;
    string name;

    while (inFile >> id) {
        inFile.ignore(); // To ignore the space after the ID (debugging)
        inFile >> name >> quantity >> price;

        // Create new item and add to inventory
        Item newItem(id, name, quantity, price);
        items.append(newItem);

        // Add the new item to the hash map
        Node* node = items.getNode(items.getSize() - 1);
        itemIndex.insert(id, node);
    }

    inFile.close();
    cout << "Data loaded successfully from inventory.txt!\n";
}

// Search for an item by ID
void Inventory::searchByID() const {
    int id;
    cout << "Enter Item ID to search: ";
    cin >> id;

    // Check if the item exists in the hash map
    if (!itemIndex.contains(id)) {
        cout << "Error: Item with ID " << id << " not found.\n";
        return;
    }

    // Get the node pointerr from the hash map
    Node* node = itemIndex.get(id);
    cout << "Item found:\n";
    node->data.display();
}
