// 2. Write a program to count the number of occurrences of a given key in a singly linked
// list and then delete all the occurrences.
// Input: Linked List : 1->2->1->2->1->3->1 , key: 1
// Output: Count: 4 , Updated Linked List: 2->2->3.

#include <iostream>

#include "linked_list.hpp"

using namespace std;

// Function to count occurrences of key
int countKey(Node* head, int key) {
  int count = 0;
  while (head != nullptr) {
    if (head->data == key)
      count++;
    head = head->next;
  }
  return count;
}

// Function to delete all occurrences of key
void deleteKey(Node*& head, int key) {
  // Remove occurrences at the head
  while (head != nullptr && head->data == key) {
    Node* temp = head;
    head = head->next;
    delete temp;
  }

  // Remove occurrences beyond the head
  Node* curr = head;
  while (curr != nullptr && curr->next != nullptr) {
    if (curr->next->data == key) {
      Node* temp = curr->next;
      curr->next = curr->next->next;
      delete temp;
    } else {
      curr = curr->next;
    }
  }
}

int main() {
  LinkedList list;

  list.insertAtEnd(1);
  list.insertAtEnd(2);
  list.insertAtEnd(1);
  list.insertAtEnd(2);
  list.insertAtEnd(1);
  list.insertAtEnd(3);
  list.insertAtEnd(1);

  cout << "Original Linked List: ";
  list.display();

  int key = 1;
  int count = countKey(list.head, key);

  deleteKey(list.head, key);

  cout << "Key: " << key << ", Count: " << count << endl;
  cout << "Updated Linked List: ";
  list.display();

  return 0;
}
