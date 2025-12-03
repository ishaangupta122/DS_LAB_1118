// Q2. Given a string, reverse it using STACK. For example “DataStructure” should be output as
// “erutcurtSataD.”

#include <iostream>

#include "stack.hpp"

using namespace std;

int main() {
  Stack<char> s;
  char val;
  int n;
  int size = (sizeof(s.stackArr) / sizeof(s.stackArr[0]));

  cout << "\nEnter how many elements you want to insert: ";
  cin >> n;
  cout << "Enter characters into stack separated by space: ";

  for (int i = 0; i < n; i++) {
    cin >> val;
    s.push(val);
  }

  cout << "\nOriginal Stack: \n";
  s.display();

  cout << "Reversed Stack with popping: \n";
  while (!s.isEmpty()) {
    s.pop();
  }

  return 0;
}