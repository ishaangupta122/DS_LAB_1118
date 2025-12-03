#include <iostream>
using namespace std;

#define MAX 100

template <typename T>

class Stack {
 public:
  T stackArr[MAX];
  int top;

  Stack() : top(-1) {}

  bool isEmpty() {
    return top < 0;
  }

  bool isFull() {
    return top >= MAX - 1;
  }

  void push(T x) {
    if (isFull()) {
      cout << "Stack overflow, cannot push!\n";
      return;
    }
    stackArr[++top] = x;
    cout << x << " pushed at top of stack\n";
  }

  void pop() {
    if (isEmpty()) {
      cout << "Stack underflow, cannot pop!\n";
    }
    T topEle = stackArr[top];
    top--;
    cout << topEle << " Popped from TOS\n";
  }

  void tos() {
    if (isEmpty()) {
      cout << "Stack underflow, no element at TOS!\n";
    } else {
      cout << "TOS: " << stackArr[top] << "\n";
    }
  }

  void display() {
    if (isEmpty()) {
      cout << "Stack is empty!\n";
      return;
    }

    for (int i = top; i >= 0; i--) {
      cout << "Index: " << i << " Element: " << stackArr[i] << "\n";
    }
    cout << "\n";
  }
};
