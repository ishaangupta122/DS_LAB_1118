// 5. Given a linked list, determine whether it contains a loop (cycle) using a hash set.
// A loop exists if some node's next pointer points to a previous node in the list.
// Input:
// 1 → 2 → 3 → 4 → 2 (back to node 2)
// Output:
// true

#include <iostream>
#include <unordered_set>
using namespace std;

struct Node {
  int data;
  Node* next;

  Node(int val) {
    data = val;
    next = nullptr;
  }
};

bool hasCycle(Node* head) {
  unordered_set<Node*> visited;
  Node* current = head;

  while (current != nullptr) {
    if (visited.find(current) != visited.end()) {
      return true;
    }
    visited.insert(current);  // mark node as visited
    current = current->next;
  }

  return false;
}

int main() {
  // Linked list with cycle
  Node* head1 = new Node(1);
  Node* node2 = new Node(2);
  Node* node3 = new Node(3);
  Node* node4 = new Node(4);

  head1->next = node2;
  node2->next = node3;
  node3->next = node4;
  node4->next = node2;

  cout << "Test Case 1: 1 - 2 - 3 - 4 - 2\n";
  cout << "Output: " << (hasCycle(head1) ? "true(has cycle)" : "false(no cycle)") << "\n";

  // Linked list without cycle
  Node* head2 = new Node(1);
  head2->next = new Node(2);
  head2->next->next = new Node(3);
  head2->next->next->next = new Node(4);

  cout << "\nTest Case 2: 1 - 2 - 3 - 4\n";
  cout << "Output: " << (hasCycle(head2) ? "true(has cycle)" : "false(no cycle)") << "\n";

  return 0;
}
