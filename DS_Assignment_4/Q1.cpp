// 1) Develop a menu driven program demonstrating the following operations on
// simple Queues: enqueue(), dequeue(), isEmpty(), isFull(), display(), and
// peek().

#include <iostream>

#include "queue.hpp"

using namespace std;

int main() {
  int choice, val;
  Queue<int> q;

  do {
    cout << "\n--- Linear Queue Menu ---" << endl;
    cout << "1. Enqueue\n2. Dequeue\n3. isEmpty\n4. isFull\n5. Get Front\n6. "
            "Get Rear\n7. Display\n8. Exit\n";
    cout << "Enter choice: ";
    cin >> choice;
    cout << endl;

    switch (choice) {
      case 1: {
        cout << "Enter value to enqueue: ";
        cin >> val;
        q.enq(val);
        break;
      }
      case 2: {
        q.deq();
        break;
      }
      case 3: {
        cout << (q.isEmpty() ? "Queue is empty" : "Queue is not empty") << endl;
        break;
      }
      case 4: {
        cout << (q.isFull() ? "Queue is full" : "Queue is not full") << endl;
        break;
      }
      case 5: {
        q.getFront();
        break;
      }
      case 6: {
        q.getRear();
        break;
      }
      case 7: {
        q.display();
        break;
      }
      case 8: {
        cout << "Exiting..." << endl;
        break;
      }
      default: {
        cout << "Invalid choice !" << endl;
        break;
      }
    }
  } while (choice != 8);

  return 0;
}