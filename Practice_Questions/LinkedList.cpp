#include <iostream>
using namespace std;

class Node {
 public:
  int data;
  Node* next;

  Node(int data) {
    data = data;
    next = nullptr;
  }
};

class LinkedList {
  Node* head;

 public:
  LinkedList() {
    head = nullptr;
  }

  void display(Node* head) {
    Node* temp = head;
    while (temp) {
      cout << temp->data << " ";
      temp = temp->next;
    }
    cout << endl;
  }

  void search(Node* head, int val) {}

  void insertion(Node* head, int val) {}

  void deletion(Node* head, int val) {}

  void length(Node* head) {}
};

int main() {
  int arr[] = {10, 2, 5, 12};

  Node* head = new Node(arr[0]);
  Node* temp = head;

  LinkedList l1;
  l1.display(temp);

  return 0;
}