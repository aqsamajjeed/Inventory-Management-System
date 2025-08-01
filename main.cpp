#include <iostream>
#include "Inventory.h"
#include "Item.h"

using namespace std;

int main() {
    Inventory inventory;
    // Load existing inventory data from file
    inventory.loadFromFile();

    int choice;
    do {
        // Using menu and switch statements for console-based UI
        cout << "\n--- Inventory Management System ---\n";
        cout << "1. Add Item\n2. Remove Item\n3. Update Item\n4. Display Inventory\n5. Search item by ID\n6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        // Switch case implemented for handling different menu options
                switch (choice) {
            case 1:
                inventory.addItem();
                break;
            case 2:
                inventory.removeItem();
                break;
            case 3:
                inventory.updateItem();
                break;
            case 4:
                inventory.displayItems();
                break;
            case 5:
                inventory.searchByID();
                break;
            case 6:
                inventory.saveToFile();
                cout << "Exiting the program...\n";
                break;
            default:
                cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 6);// Loop until the user chooses to exit
    return 0;
}
