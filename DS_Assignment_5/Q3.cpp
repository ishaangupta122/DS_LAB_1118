// 3. Write a program to find the middle of a linked list.
// Input: 1->2->3->4->5
// Output: 3

#include <iostream>

#include "linked_list.hpp"

using namespace std;

int findMiddle(Node* head) {
  if (head == nullptr)
    return -1;

  Node* slow = head;
  Node* fast = head;

  while (fast != nullptr && fast->next != nullptr) {
    slow = slow->next;
    fast = fast->next->next;
  }

  return slow->data;
}

int main() {
  LinkedList list;

  list.insertAtEnd(1);
  list.insertAtEnd(2);
  list.insertAtEnd(3);
  list.insertAtEnd(4);
  list.insertAtEnd(5);

  cout << "Linked List: ";
  list.display();

  int middle = findMiddle(list.head);

  cout << "Middle Element: " << middle << endl;

  return 0;
}
