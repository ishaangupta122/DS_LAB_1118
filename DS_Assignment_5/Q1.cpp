// Develop a menu driven program for the following operations on a Singly Linked List.
// (a) Insertion at the beginning.
// (b) Insertion at the end.
// (c) Insertion in between (before or after a node having a specific value, say 'Insert a
// new Node 35 before/after the Node 30').
// (d) Deletion from the beginning.
// (e) Deletion from the end.
// (f) Deletion of a specific node, say 'Delete Node 60').
// (g) Search for a node and display its position from head.
// (h) Display all the node values.

#include <iostream>

#include "linked_list.hpp"

using namespace std;

int main() {
  LinkedList list;
  int choice, value, target;

  while (true) {
    cout << "\n--- Singly Linked List Menu ---\n";
    cout << "1. Insert at beginning\n";
    cout << "2. Insert at end\n";
    cout << "3. Insert before a value\n";
    cout << "4. Insert after a value\n";
    cout << "5. Delete from beginning\n";
    cout << "6. Delete from end\n";
    cout << "7. Delete a specific node\n";
    cout << "8. Search for a node\n";
    cout << "9. Display all nodes\n";
    cout << "0. Exit\n";
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
      case 1: {
        cout << "Enter value: ";
        cin >> value;
        list.insertAtBeginning(value);
        break;
      }
      case 2: {
        cout << "Enter value: ";
        cin >> value;
        list.insertAtEnd(value);
        break;
      }
      case 3: {
        cout << "Enter target value: ";
        cin >> target;
        cout << "Enter value to insert: ";
        cin >> value;
        list.insertBefore(target, value);
        break;
      }
      case 4: {
        cout << "Enter target value: ";
        cin >> target;
        cout << "Enter value to insert: ";
        cin >> value;
        list.insertAfter(target, value);
        break;
      }
      case 5: {
        list.deleteFromBeginning();
        break;
      }
      case 6: {
        list.deleteFromEnd();
        break;
      }
      case 7: {
        cout << "Enter value to delete: ";
        cin >> value;
        list.deleteNode(value);
        break;
      }
      case 8: {
        cout << "Enter value to search: ";
        cin >> value;
        int pos = list.search(value);
        if (pos != -1) {
          cout << "Node found at position " << pos << endl;
        } else {
          cout << "Node not found." << endl;
        }
        break;
      }
      case 9: {
        cout << "Linked List: ";
        list.display();
        break;
      }
      case 0: {
        return 0;
      }
      default: {
        cout << "Invalid choice." << endl;
        break;
      }
    }
  }
}