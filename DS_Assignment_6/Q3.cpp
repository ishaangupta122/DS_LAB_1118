// 3. Write a program to find size of
// i. Doubly Linked List.
// ii. Circular Doubly Linked List.

#include <iostream>

#include "linked_list.hpp"

using namespace std;

void sizeOfDLL(Node* head) {
  Node* curr = head;
  int dll_size = 0;

  while (curr != nullptr) {
    dll_size++;
    curr = curr->next;
  }
  cout << "Size of Doubly Linked List: " << dll_size << "\n";
}

void sizeOfCLL(Node* head) {
  Node* curr = head;
  int cll_size = 0;

  if (curr != nullptr) {
    do {
      cll_size++;
      curr = curr->next;
    } while (curr != head);
  }
  cout << "Size of Circular Linked List: " << cll_size << "\n";
}

int main() {
  DoublyLinkedList dll;
  dll.insertAtEnd(20);
  dll.insertAtEnd(100);
  dll.insertAtEnd(40);
  dll.insertAtEnd(80);
  dll.insertAtEnd(60);

  CircularLinkedList cll;
  cll.insertAtEnd(20);
  cll.insertAtEnd(100);
  cll.insertAtEnd(40);
  cll.insertAtEnd(80);
  cll.insertAtEnd(60);

  // Doubly Linked List
  sizeOfDLL(dll.head);

  // Circular Linked List
  sizeOfCLL(cll.head);

  return 0;
}
