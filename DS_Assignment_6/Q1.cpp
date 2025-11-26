// 1. Develop a menu driven program for the following operations of on a Circular as well
// as a Doubly Linked List.
// (a) Insertion anywhere in the linked list (As a first node, as a last node, and
// after/before a specific node).
// (b) Deletion of a specific node, say 'Delete Node 60'. That mean the node to be
// deleted may appear as a head node, last node or a node in between.
// (c) Search for a node.

#include <iostream>

#include "linked_list.hpp"

using namespace std;

int main() {
  DoublyLinkedList dll;
  CircularLinkedList cll;

  int mainChoice, choice, value, target;

  while (true) {
    cout << "\n--- Main Menu ---\n";
    cout << "1. Operate on Doubly Linked List\n";
    cout << "2. Operate on Circular Linked List\n";
    cout << "0. Exit\n";
    cout << "Enter your choice: ";
    cin >> mainChoice;

    if (mainChoice == 0)
      break;

    switch (mainChoice) {
      case 1: {
        while (true) {
          cout << "\n--- Doubly Linked List Menu ---\n";
          cout << "1. Insert at beginning\n";
          cout << "2. Insert at end\n";
          cout << "3. Insert before a value\n";
          cout << "4. Insert after a value\n";
          cout << "5. Delete a specific node\n";
          cout << "6. Search for a node\n";
          cout << "7. Display all nodes\n";
          cout << "0. Back to main menu\n";
          cout << "Enter your choice: ";
          cin >> choice;

          if (choice == 0)
            break;

          switch (choice) {
            case 1:
              cout << "Enter value: ";
              cin >> value;
              dll.insertAtBeginning(value);
              break;
            case 2:
              cout << "Enter value: ";
              cin >> value;
              dll.insertAtEnd(value);
              break;
            case 3:
              cout << "Enter target value: ";
              cin >> target;
              cout << "Enter value to insert: ";
              cin >> value;
              dll.insertBefore(target, value);
              break;
            case 4:
              cout << "Enter target value: ";
              cin >> target;
              cout << "Enter value to insert: ";
              cin >> value;
              dll.insertAfter(target, value);
              break;
            case 5:
              cout << "Enter value to delete: ";
              cin >> value;
              dll.deleteNode(value);
              break;
            case 6:
              cout << "Enter value to search: ";
              cin >> value;
              if (dll.search(value))
                cout << "Node found." << endl;
              else
                cout << "Node not found." << endl;
              break;
            case 7:
              cout << "Doubly Linked List: ";
              dll.display();
              break;
            default:
              cout << "Invalid choice." << endl;
              break;
          }
        }
        break;
      }

      case 2: {
        while (true) {
          cout << "\n--- Circular Linked List Menu ---\n";
          cout << "1. Insert at beginning\n";
          cout << "2. Insert at end\n";
          cout << "3. Insert after a value\n";
          cout << "4. Delete a specific node\n";
          cout << "5. Search for a node\n";
          cout << "6. Display all nodes\n";
          cout << "0. Back to main menu\n";
          cout << "Enter your choice: ";
          cin >> choice;

          if (choice == 0)
            break;

          switch (choice) {
            case 1:
              cout << "Enter value: ";
              cin >> value;
              cll.insertAtBeginning(value);
              break;
            case 2:
              cout << "Enter value: ";
              cin >> value;
              cll.insertAtEnd(value);
              break;
            case 3:
              cout << "Enter target value: ";
              cin >> target;
              cout << "Enter value to insert: ";
              cin >> value;
              cll.insertAfter(target, value);
              break;
            case 4:
              cout << "Enter value to delete: ";
              cin >> value;
              cll.deleteNode(value);
              break;
            case 5:
              cout << "Enter value to search: ";
              cin >> value;
              if (cll.search(value))
                cout << "Node found." << endl;
              else
                cout << "Node not found." << endl;
              break;
            case 6:
              cout << "Circular Linked List: ";
              cll.display();
              break;
            default:
              cout << "Invalid choice." << endl;
              break;
          }
        }
        break;
      }

      default:
        cout << "Invalid choice. Please select 1 or 2." << endl;
    }
  }

  cout << "Exiting program." << endl;
  return 0;
}
