// 6. You are given a binary tree (not a binary search tree). Write a program to check if
// the tree contains any duplicate node values using hash set.
// Your task is to:
// 1. Return true (or print "Duplicates Found") if there exists at least one duplicate value.
// 2. Otherwise, return false (or print "No Duplicates")

#include <iostream>
#include <unordered_set>
using namespace std;

struct Node {
  int data;
  Node* left;
  Node* right;

  Node(int val) {
    data = val;
    left = nullptr;
    right = nullptr;
  }
};

bool checkDuplicates(Node* root, unordered_set<int>& seen) {
  if (root == nullptr) {
    return false;
  }

  if (seen.find(root->data) != seen.end()) {
    return true;
  }

  seen.insert(root->data);

  return checkDuplicates(root->left, seen) || checkDuplicates(root->right, seen);
}

bool hasDuplicates(Node* root) {
  unordered_set<int> seen;
  return checkDuplicates(root, seen);
}

int main() {
  // Tree with duplicates
  Node* root1 = new Node(1);
  root1->left = new Node(2);
  root1->right = new Node(3);
  root1->left->left = new Node(4);
  root1->left->right = new Node(2);

  cout << "Tree 1:\n";
  cout << "Output: " << (hasDuplicates(root1) ? "Duplicates Found" : "No Duplicates") << "\n";

  // Tree without duplicates
  Node* root2 = new Node(1);
  root2->left = new Node(2);
  root2->right = new Node(3);
  root2->left->left = new Node(4);
  root2->left->right = new Node(5);

  cout << "\nTree 2\n";
  cout << "Output: " << (hasDuplicates(root2) ? "Duplicates Found" : "No Duplicates") << "\n";

  return 0;
}
