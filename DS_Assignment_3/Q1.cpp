// Q1. Develop a menu driven program demonstrating the following operations on a
// Stack using array: (i) push(), (ii) pop(), (iii) isEmpty(), (iv) isFull(),
// (v) display(), and (vi) peek().

#include <iostream>

#include "stack.hpp"

using namespace std;

int main() {
  int choice, val;
  Stack<int> s;
  do {
    cout << "\n--- Stack Menu ---\n";
    cout << "1. Push\n2. Pop\n3. Peek\n4. isEmpty\n5. isFull\n6. Display\n7. "
            "Exit\n";
    cout << "\nEnter your choice: ";
    cin >> choice;

    switch (choice) {
      case 1:
        cout << "Enter element to push: ";
        cin >> val;
        s.push(val);
        break;

      case 2:
        s.pop();
        break;

      case 3:
        s.tos();
        break;

      case 4:
        cout << (s.isEmpty() ? "Stack is empty." : "Stack is not empty.") << endl;
        break;

      case 5:
        cout << (s.isFull() ? "Stack is full." : "Stack is not full.") << endl;
        break;

      case 6:
        s.display();
        break;

      case 7:
        cout << "Exiting program." << endl;
        break;

      default:
        cout << "Invalid choice. Try again." << endl;
    }
  } while (choice != 7);

  return 0;
}
