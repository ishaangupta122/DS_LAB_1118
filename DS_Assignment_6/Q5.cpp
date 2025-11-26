// 5. Write a program to check if a linked list is Circular Linked List or not .

#include <iostream>

#include "linked_list.hpp"

using namespace std;

void is_circular(Node* head) {
  Node* curr = head;

  if (head != nullptr) {
    curr = head->next;
    while (curr != nullptr && curr != head) {
      curr = curr->next;
    }
  }

  if (curr == head) {
    cout << "It is a Circular Linked List.\n";
  } else {
    cout << "It is not a Circular Linked List !\n";
  }
}

int main() {
  DoublyLinkedList dll;
  dll.insertAtEnd(2);
  dll.insertAtEnd(4);
  dll.insertAtEnd(6);
  dll.insertAtEnd(7);
  dll.insertAtEnd(5);

  CircularLinkedList cll;
  cll.insertAtEnd(10);
  cll.insertAtEnd(20);
  cll.insertAtEnd(30);
  cll.insertAtEnd(40);

  is_circular(dll.head);
  is_circular(cll.head);

  return 0;
}
