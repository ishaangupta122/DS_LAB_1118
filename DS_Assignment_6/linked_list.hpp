#include <iostream>
using namespace std;

class Node {
 public:
  int data;
  Node* next;
  Node* prev;

  Node(int data) {
    this->data = data;
    this->next = nullptr;
    this->prev = nullptr;
  }
};

class DoublyLinkedList {
 public:
  Node* head;
  Node* tail;

  DoublyLinkedList() {
    head = tail = nullptr;
  }

  ~DoublyLinkedList() {
    Node* curr = head;
    while (curr) {
      Node* next = curr->next;
      delete curr;
      curr = next;
    }
  }

  // Insert at beginning
  void insertAtBeginning(int data) {
    Node* temp = new Node(data);
    if (head)
      head->prev = temp;
    temp->next = head;
    head = temp;
    if (!tail)
      tail = temp;
  }

  // Insert at end
  void insertAtEnd(int data) {
    Node* temp = new Node(data);
    if (!tail) {
      head = tail = temp;
      return;
    }
    tail->next = temp;
    temp->prev = tail;
    tail = temp;
  }

  // Insert after a node with given value
  void insertAfter(int value, int data) {
    Node* curr = head;
    while (curr && curr->data != value)
      curr = curr->next;
    if (!curr) {
      cout << "Value " << value << " not found.\n";
      return;
    }
    Node* temp = new Node(data);
    temp->next = curr->next;
    temp->prev = curr;
    if (curr->next)
      curr->next->prev = temp;
    curr->next = temp;
    if (curr == tail)
      tail = temp;
  }

  // Insert before a node with given value
  void insertBefore(int value, int data) {
    Node* curr = head;
    while (curr && curr->data != value)
      curr = curr->next;
    if (!curr) {
      cout << "Value " << value << " not found.\n";
      return;
    }
    Node* temp = new Node(data);
    temp->next = curr;
    temp->prev = curr->prev;
    if (curr->prev)
      curr->prev->next = temp;
    curr->prev = temp;
    if (curr == head)
      head = temp;
  }

  // Delete node by value
  void deleteNode(int value) {
    Node* curr = head;
    while (curr) {
      if (curr->data == value) {
        if (curr == head && curr == tail) {
          head = tail = nullptr;
        } else if (curr == head) {
          head = head->next;
          head->prev = nullptr;
        } else if (curr == tail) {
          tail = tail->prev;
          tail->next = nullptr;
        } else {
          curr->prev->next = curr->next;
          curr->next->prev = curr->prev;
        }
        delete curr;
        return;
      }
      curr = curr->next;
    }
    cout << "Value " << value << " not found.\n";
  }

  // Search node
  bool search(int value) {
    Node* curr = head;
    while (curr) {
      if (curr->data == value)
        return true;
      curr = curr->next;
    }
    return false;
  }

  // Display
  void display() {
    Node* curr = head;
    while (curr) {
      cout << curr->data << " ";
      curr = curr->next;
    }
    cout << endl;
  }
};

class CircularLinkedList {
 public:
  Node* head;

  CircularLinkedList() {
    head = nullptr;
  }

  ~CircularLinkedList() {
    if (!head)
      return;
    Node* curr = head->next;
    while (curr != head) {
      Node* next = curr->next;
      delete curr;
      curr = next;
    }
    delete head;
    head = nullptr;
  }

  // Insert at beginning
  void insertAtBeginning(int data) {
    Node* temp = new Node(data);
    if (!head) {
      head = temp;
      temp->next = head;
      return;
    }
    Node* tail = head;
    while (tail->next != head)
      tail = tail->next;
    temp->next = head;
    tail->next = temp;
    head = temp;
  }

  // Insert at end
  void insertAtEnd(int data) {
    Node* temp = new Node(data);
    if (!head) {
      head = temp;
      temp->next = head;
      return;
    }
    Node* tail = head;
    while (tail->next != head)
      tail = tail->next;
    tail->next = temp;
    temp->next = head;
  }

  // Insert after a node with given value
  void insertAfter(int value, int data) {
    if (!head)
      return;
    Node* curr = head;
    do {
      if (curr->data == value) {
        Node* temp = new Node(data);
        temp->next = curr->next;
        curr->next = temp;
        return;
      }
      curr = curr->next;
    } while (curr != head);
    cout << "Value " << value << " not found.\n";
  }

  // Delete node by value
  void deleteNode(int value) {
    if (!head)
      return;

    Node* curr = head;
    Node* prev = nullptr;

    // special case: head node
    do {
      if (curr->data == value) {
        if (curr == head) {
          Node* tail = head;
          while (tail->next != head)
            tail = tail->next;
          if (head->next == head) {
            delete head;
            head = nullptr;
            return;
          }
          Node* temp = head;
          head = head->next;
          tail->next = head;
          delete temp;
          return;
        } else {
          prev->next = curr->next;
          delete curr;
          return;
        }
      }
      prev = curr;
      curr = curr->next;
    } while (curr != head);

    cout << "Value " << value << " not found.\n";
  }

  // Search node
  bool search(int value) {
    if (!head)
      return false;
    Node* curr = head;
    do {
      if (curr->data == value)
        return true;
      curr = curr->next;
    } while (curr != head);
    return false;
  }

  // Display
  void display() {
    if (!head) {
      cout << "List is empty\n";
      return;
    }
    Node* curr = head;
    do {
      cout << curr->data << " ";
      curr = curr->next;
    } while (curr != head);
    cout << endl;
  }
};
