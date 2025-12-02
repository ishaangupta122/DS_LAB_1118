// 1. Given an integer array, check if it contains any duplicates using hash set.
// Input: nums = [1, 2, 3, 1]
// Output: true

#include <iostream>
#include <unordered_set>
using namespace std;

bool checkDup(int arr[], int n) {
  unordered_set<int> dup;

  for (int i = 0; i < n; i++) {
    if (dup.find(arr[i]) != dup.end()) {
      return true;
    }
    dup.insert(arr[i]);
  }

  return false;
}
int main() {
  int arr1[] = {1, 2, 3, 1};
  int arr2[] = {1, 2, 3, 4};

  int n1 = sizeof(arr1) / sizeof(arr1[0]);
  int n2 = sizeof(arr2) / sizeof(arr2[0]);

  cout << "\nInput Array(1): ";
  for (int i = 0; i < n1; i++) {
    cout << arr1[i] << " ";
  }
  cout << "\n";

  if (checkDup(arr1, n1)) {
    cout << "Output: Duplicates Found\n";
  } else {
    cout << "Output: No Duplicates\n";
  }

  cout << "\nInput Array(2): ";
  for (int i = 0; i < n2; i++) {
    cout << arr2[i] << " ";
  }
  cout << "\n";

  if (checkDup(arr2, n2)) {
    cout << "Output: Duplicates Found\n";
  } else {
    cout << "Output: No Duplicates\n";
  }

  return 0;
}