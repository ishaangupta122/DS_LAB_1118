// 2. Display all the node values in a circular linked list, repeating value of head node at the
// end too.
// Input: 20 → 100 → 40 → 80 → 60,
// Output: 20 100 40 80 60 20.

#include "linked_list.hpp"
using namespace std;

int main() {
  CircularLinkedList cdll;
  cdll.insertAtEnd(20);
  cdll.insertAtEnd(100);
  cdll.insertAtEnd(40);
  cdll.insertAtEnd(80);
  cdll.insertAtEnd(60);

  cout << "\nNode in Circular Linked List: ";
  cout << cdll.head->data << " ";

  Node* curr = cdll.head->next;
  while (curr != cdll.head) {
    cout << curr->data << " ";
    curr = curr->next;
  }
  cout << curr->data << "\n";
}