// 2) Develop a menu driven program demonstrating the following operations on Circular Queues:
// enqueue(), dequeue(), isEmpty(), isFull(), display(), and peek().

#include <iostream>

#include "queue.hpp"

using namespace std;

int main() {
  CircularQueue<int> cq;
  int choice, val;

  while (true) {
    cout << "\n--- Circular Queue Menu ---" << endl;
    cout << "\n1. Enqueue\n2. Dequeue\n3. isEmpty\n4. isFull\n5. Peek\n6. Display\n7. Exit\n";
    cout << "Enter choice: ";
    cin >> choice;

    switch (choice) {
      case 1:
        cout << "Enter value: ";
        cin >> val;
        cq.enq(val);
        break;
      case 2:
        cq.deq();
        break;
      case 3:
        cout << (cq.isEmpty() ? "Queue is empty" : "Queue is not empty") << endl;
        break;
      case 4:
        cout << (cq.isFull() ? "Queue is full" : "Queue is not full") << endl;
        break;
      case 5:
        cq.peek();
        break;
      case 6:
        cq.display();
        break;
      case 7:
        cout << "Exiting..." << endl;
        return 0;
      default:
        cout << "Invalid choice!" << endl;
    }
  }
}
