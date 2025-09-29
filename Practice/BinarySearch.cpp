#include <iostream>
using namespace std;

int BinarySearch(int arr[], int l, int r, int k) {
  while (l <= r) {
    int m = (l + r) / 2;
    if (k == arr[m]) {
      return m;
    } else if (k < arr[m]) {
      r = m - 1;
    } else {
      l = m + 1;
    }
  }
  return -1;
}

int BinarySearchRecursive(int arr[], int l, int r, int k) {
  if (l > r) {
    return -1;
  }
  int m = (l + r) / 2;
  if (k == arr[m]) {
    return m;
  } else if (k < arr[m]) {
    BinarySearchRecursive(arr, l, m - 1, k);
  } else {
    BinarySearchRecursive(arr, m + 1, r, k);
  }
}

int main() {
  int l, r, k;
  int arr[] = {1, 2, 3, 4, 5, 6, 7, 9, 20};
  l = 0;
  r = sizeof(arr) / sizeof(arr[0]) - 1;
  k = 7;

  int index = BinarySearch(arr, l, r, k);
  int indexRec = BinarySearchRecursive(arr, l, r, k);

  cout << "Initial Array: ";
  for (int i = 0; i <= r; i++) {
    cout << arr[i] << " ";
  }

  cout << "\nElement found at index (Simple): " << index << endl;
  cout << "Element found at index (Recursion): " << indexRec << endl;

  return 0;
}