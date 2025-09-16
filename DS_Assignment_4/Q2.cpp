// 2) Develop a menu driven program demonstrating the following operations on Circular Queues:
// enqueue(), dequeue(), isEmpty(), isFull(), display(), and peek().

#include <iostream>
using namespace std;

class CircularQueue {
  int* arr;
  int front, rear, size;

 public:
  CircularQueue(int s) {
    size = s;
    arr = new int[size];
    front = rear = -1;
  }

  bool isFull() {
    return (front == 0 && rear == size - 1) || (front == rear + 1);
  }

  bool isEmpty() {
    return front == -1;
  }

  void enqueue(int value) {
    if (isFull()) {
      cout << "Queue is Full\n";
      return;
    }
    if (front == -1)
      front = 0;
    rear = (rear + 1) % size;
    arr[rear] = value;
  }

  int dequeue() {
    if (isEmpty()) {
      cout << "Queue is Empty\n";
      return -1;
    }
    int data = arr[front];
    if (front == rear)
      front = rear = -1;
    else
      front = (front + 1) % size;
    return data;
  }

  void display() {
    if (isEmpty()) {
      cout << "Queue is Empty\n";
      return;
    }
    int i = front;
    while (true) {
      cout << arr[i] << " ";
      if (i == rear)
        break;
      i = (i + 1) % size;
    }
    cout << endl;
  }

  void peek() {
    if (isEmpty())
      cout << "Queue is Empty\n";
    else
      cout << "Front element: " << arr[front] << endl;
  }
};

int main() {
  CircularQueue cq(5);
  int choice, val;

  while (true) {
    cout << "\n--- Circular Queue Menu ---" << endl;
    cout << "\n1. Enqueue\n2. Dequeue\n3. Display\n4. Peek\n5. Exit\n";
    cout << "Enter choice: ";
    cin >> choice;

    switch (choice) {
      case 1:
        cout << "Enter value: ";
        cin >> val;
        cq.enqueue(val);
        break;
      case 2:
        cout << "Dequeued: " << cq.dequeue() << endl;
        break;
      case 3:
        cq.display();
        break;
      case 4:
        cq.peek();
        break;
      case 5:
        return 0;
      default:
        cout << "Invalid choice!\n";
    }
  }
}
