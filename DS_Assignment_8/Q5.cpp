// 5. Implement Heapsort (Increasing / Decreasing order).

#include <iostream>
using namespace std;

void heapify(int arr[], int n, int i, bool maxHeap) {
  int largest = i;
  int left = 2 * i + 1;
  int right = 2 * i + 2;

  if (maxHeap) {
    if (left < n && arr[left] > arr[largest]) {
      largest = left;
    }

    if (right < n && arr[right] > arr[largest]) {
      largest = right;
    }
  } else {
    if (left < n && arr[left] < arr[largest]) {
      largest = left;
    }

    if (right < n && arr[right] < arr[largest]) {
      largest = right;
    }
  }

  if (largest != i) {
    int temp = arr[i];
    arr[i] = arr[largest];
    arr[largest] = temp;

    heapify(arr, n, largest, maxHeap);
  }
}

void heapSort(int arr[], int n, bool ascending) {
  for (int i = n / 2 - 1; i >= 0; i--) {
    heapify(arr, n, i, ascending);
  }

  for (int i = n - 1; i > 0; i--) {
    int temp = arr[0];
    arr[0] = arr[i];
    arr[i] = temp;

    heapify(arr, i, 0, ascending);
  }
}

void printArray(int arr[], int n) {
  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
  cout << "\n";
}

int main() {
  int arr1[] = {12, 11, 13, 5, 6, 7};
  int n1 = 6;

  cout << "\nOriginal array: ";
  printArray(arr1, n1);

  heapSort(arr1, n1, true);
  cout << "Sorted in Increasing order: ";
  printArray(arr1, n1);

  int arr2[] = {12, 11, 13, 5, 6, 7};
  int n2 = 6;

  cout << "\nOriginal array: ";
  printArray(arr2, n2);

  heapSort(arr2, n2, false);
  cout << "Sorted in Decreasing order: ";
  printArray(arr2, n2);

  return 0;
}