// 4. Write a program to reverse a linked list.
// Input: 1->2->3->4->NULL
// Output: 4->3->2->1->NULL

#include <iostream>

#include "linked_list.hpp"

using namespace std;

Node* reverseList(Node* head) {
  Node* prev = nullptr;
  Node* curr = head;

  while (curr != nullptr) {
    Node* nextNode = curr->next;  // store next
    curr->next = prev;            // reverse link
    prev = curr;                  // move prev forward
    curr = nextNode;              // move curr forward
  }

  return prev;  // new head
}

int main() {
  LinkedList list;

  list.insertAtEnd(1);
  list.insertAtEnd(2);
  list.insertAtEnd(3);
  list.insertAtEnd(4);

  cout << "Original List: ";
  list.display();

  list.head = reverseList(list.head);

  cout << "Reversed List: ";
  list.display();

  return 0;
}
