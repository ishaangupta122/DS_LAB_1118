#include <iostream>
using namespace std;

class Node {
 public:
  int data;
  Node* next;
  Node(int value) {
    data = value;
    next = nullptr;
  }
};

class LinkedList {
 public:
  Node* head;
  LinkedList() {
    head = nullptr;
  }

  //   Insert at Beginning
  void insertAtBeginning(int value) {
    Node* newNode = new Node(value);
    newNode->next = head;
    head = newNode;
  }

  //   Insert at End
  void insertAtEnd(int value) {
    Node* newNode = new Node(value);
    if (!head) {
      head = newNode;
      return;
    }
    Node* temp = head;
    while (temp->next) {
      temp = temp->next;
    }
    temp->next = newNode;
  }

  //   Insert Before
  void insertBefore(int target, int value) {
    if (!head) {
      return;
    }
    if (head->data == target) {
      insertAtBeginning(value);
      return;
    }
    Node* temp = head;
    while (temp->next && temp->next->data != target) {
      temp = temp->next;
    }
    if (temp->next) {
      Node* newNode = new Node(value);
      newNode->next = temp->next;
      temp->next = newNode;
    }
  }

  //   Insert After
  void insertAfter(int target, int value) {
    Node* temp = head;
    while (temp && temp->data != target) {
      temp = temp->next;
    }
    if (temp) {
      Node* newNode = new Node(value);
      newNode->next = temp->next;
      temp->next = newNode;
    }
  }

  //   Delete from Beginning
  void deleteFromBeginning() {
    if (!head) {
      return;
    }
    Node* temp = head;
    head = head->next;
    delete temp;
  }

  //   Delete from End
  void deleteFromEnd() {
    if (!head) {
      return;
    }
    if (!head->next) {
      delete head;
      head = nullptr;
      return;
    }
    Node* temp = head;
    while (temp->next->next) {
      temp = temp->next;
    }
    delete temp->next;
    temp->next = nullptr;
  }

  //   Delete a Specific Node
  void deleteNode(int value) {
    if (!head) {
      return;
    }
    if (head->data == value) {
      Node* temp = head;
      head = head->next;
      delete temp;
      return;
    }
    Node* temp = head;
    while (temp->next && temp->next->data != value) {
      temp = temp->next;
    }
    if (temp->next) {
      Node* delNode = temp->next;
      temp->next = delNode->next;
      delete delNode;
    }
  }

  //   Search Node
  int search(int value) {
    Node* temp = head;
    int pos = 1;
    while (temp) {
      if (temp->data == value) {
        return pos;
      }
      temp = temp->next;
      pos++;
    }
    return -1;
  }

  //   Display Linked List
  void display() {
    Node* temp = head;
    while (temp) {
      cout << temp->data << " ";
      temp = temp->next;
    }
    cout << endl;
  }

  //   Delete nodes after program termination
  ~LinkedList() {
    Node* curr = head;
    while (curr) {
      Node* nxt = curr->next;
      delete curr;
      curr = nxt;
    }
  }
};
