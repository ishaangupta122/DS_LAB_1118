#include <iostream>
using namespace std;

#define MAX 100

template <typename T>

class Queue {
 public:
  T queue[MAX];
  int front, rear;

  Queue() {
    front = -1;
    rear = -1;
  }

  bool isEmpty() {
    if (front == -1) {
      return true;
    }
    return false;
  }

  bool isFull() {
    if (rear == MAX - 1) {
      return true;
    }
    return false;
  }

  void enq(T x) {
    if (isFull()) {
      cout << "Queue full, cannot enqueue !\n";
      return;
    }
    if (isEmpty()) {
      front = rear = 0;
    } else {
      rear++;
    }

    queue[rear] = x;
    cout << x << " Enqueued at " << rear << "\n";
  }

  void deq() {
    if (isEmpty()) {
      cout << "Queue empty, cannot dequeue !\n";
    } else {
      T x = queue[front];
      cout << x << " dequeued from " << front << " index\n";
      if (front == rear) {
        front = rear = -1;
      } else {
        front++;
      }
    }
  }

  void getFront() {
    if (isEmpty()) {
      cout << "Queue empty !\n";
    } else {
      cout << queue[front] << " at front\n";
    }
  }

  void getRear() {
    if (isEmpty()) {
      cout << "Queue empty !\n";
    } else {
      cout << queue[rear] << " at rear\n";
    }
  }

  void display() {
    if (isEmpty()) {
      cout << "Queue is empty !" << endl;
      return;
    }
    cout << "Queue elements are: " << endl;
    for (int i = front; i <= rear; i++) {
      cout << queue[i] << " ";
    }
    cout << "\n";
  }
};

template <typename T>

class CircularQueue {
 public:
  T circQue[MAX];
  int front, rear;

  CircularQueue() {
    front = rear = -1;
  }

  bool isEmpty() {
    return front == -1;
  }

  bool isFull() {
    return (front == (rear + 1) % MAX);
  }

  void enq(T x) {
    if (isFull()) {
      cout << "Queue full, cannot insert!\n";
      return;
    }

    if (isEmpty()) {
      front = rear = 0;
    } else {
      rear = (rear + 1) % MAX;
    }

    circQue[rear] = x;
    cout << x << " inserted at index " << rear << "\n";
  }

  void deq() {
    if (isEmpty()) {
      cout << "Queue empty, cannot delete!\n";
      return;
    }

    int oldIndex = front;
    T ele = circQue[front];

    if (front == rear) {
      front = rear = -1;
    } else {
      front = (front + 1) % MAX;
    }

    cout << ele << " deleted from index " << oldIndex << "\n";
  }

  void peek() {
    if (isEmpty()) {
      cout << "Queue Empty !\n";
      return;
    }
    if (front == rear) {
      cout << "Only one element exits: \n";
      cout << "Element: " << circQue[front] << " at index " << front << "\n";
    } else {
      cout << "Front: " << circQue[front] << " at index " << front << "\n";
      cout << "Rear: " << circQue[rear] << " at index " << rear << "\n";
    }
  }

  void display() {
    if (isEmpty()) {
      cout << "Queue empty!\n";
      return;
    }

    int i = front;
    cout << "Queue elements are: \n";

    while (true) {
      cout << circQue[i] << " at index " << i << " \n";
      if (i == rear) {
        break;
      }
      i = (i + 1) % MAX;
    }
    cout << "\n";
  }
};
