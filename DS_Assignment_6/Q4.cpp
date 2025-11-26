// 4. Write a program to check if a doubly linked list of characters is palindrome or not .

#include <iostream>

#include "linked_list.hpp"

using namespace std;

void isPalindrome(Node* head, Node* tail) {
  Node* head_curr = head;
  Node* tail_curr = tail;
  bool palindrome = true;

  while (head_curr != nullptr && tail_curr != nullptr && head_curr != tail_curr &&
         head_curr->prev != tail_curr) {
    if (head_curr->data != tail_curr->data) {
      palindrome = false;
      break;
    }
    head_curr = head_curr->next;
    tail_curr = tail_curr->prev;
  }

  if (palindrome && head_curr != nullptr && tail_curr != nullptr &&
      head_curr->data != tail_curr->data) {
    palindrome = false;
  }

  if (palindrome) {
    cout << "DLL of characters is a palindrome !\n";
  } else {
    cout << "DLL of characters is not a palindrome.\n";
  }
}

int main() {
  DoublyLinkedList dll;
  dll.insertAtEnd('l');
  dll.insertAtEnd('e');
  dll.insertAtEnd('v');
  dll.insertAtEnd('e');
  dll.insertAtEnd('l');

  isPalindrome(dll.head, dll.tail);

  return 0;
}
