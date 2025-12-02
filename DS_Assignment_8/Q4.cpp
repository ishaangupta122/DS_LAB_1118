// 4. Write a program to determine whether a given binary tree is a BST or not.

#include <climits>
#include <iostream>
using namespace std;

struct Node {
  int data;
  Node* left;
  Node* right;

  Node(int val) {
    data = val;
    left = NULL;
    right = NULL;
  }
};

bool isBSTUtil(Node* root, int minVal, int maxVal) {
  if (root == NULL) {
    return true;
  }

  if (root->data <= minVal || root->data >= maxVal) {
    return false;
  }

  return isBSTUtil(root->left, minVal, root->data) && isBSTUtil(root->right, root->data, maxVal);
}

bool isBST(Node* root) {
  return isBSTUtil(root, INT_MIN, INT_MAX);
}

void inorder(Node* root) {
  if (root == NULL) {
    return;
  }

  inorder(root->left);
  cout << root->data << " ";
  inorder(root->right);
}

int main() {
  // Test Case 1: Valid BST
  Node* root1 = new Node(50);
  root1->left = new Node(30);
  root1->right = new Node(70);
  root1->left->left = new Node(20);
  root1->left->right = new Node(40);
  root1->right->left = new Node(60);
  root1->right->right = new Node(80);

  cout << "\nTest Case 1: Valid BST\n";
  cout << "Tree (Inorder): ";
  inorder(root1);
  cout << "\n";

  if (isBST(root1)) {
    cout << "Result: The tree IS a BST\n";
  } else {
    cout << "Result: The tree is NOT a BST\n";
  }

  // Test Case 2: Invalid BST
  Node* root2 = new Node(50);
  root2->left = new Node(30);
  root2->right = new Node(70);
  root2->left->left = new Node(20);
  root2->left->right = new Node(60);  // Invalid: 60 > 50

  cout << "\nTest Case 2: Invalid BST\n";
  cout << "Tree (Inorder): ";
  inorder(root2);
  cout << "\n";

  if (isBST(root2)) {
    cout << "Result: The tree IS a BST\n";
  } else {
    cout << "Result: The tree is NOT a BST\n";
  }

  return 0;
}