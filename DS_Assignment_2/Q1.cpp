// 1) Implement the binary search algorithm, regarded as a fast search algorithm
// with run-time complexity of Ο(log n) in comparison to the Linear Search.

#include <iostream>
using namespace std;

int binarySearch(int arr[], int n, int key) {
  int low = 0, high = n - 1;
  while (low <= high) {
    int mid = (low + high) / 2;
    if (arr[mid] == key)
      return mid;
    else if (arr[mid] < key)
      low = mid + 1;
    else
      high = mid - 1;
  }
  return -1;  // not found
}

int main() {
  int arr[] = {2, 4, 6, 8, 10, 12};
  int n = 6, key = 10;
  int result = binarySearch(arr, n, key);
  if (result != -1)
    cout << "Element found at index " << result;
  else
    cout << "Element not found";
  return 0;
}
