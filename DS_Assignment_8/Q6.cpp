// 6. Implement priority queues using heaps.

#include <iostream>
using namespace std;

class PriorityQueue {
 private:
  int arr[100];
  int size;

  void heapifyUp(int index) {
    while (index > 0) {
      int parent = (index - 1) / 2;

      if (arr[index] > arr[parent]) {
        int temp = arr[index];
        arr[index] = arr[parent];
        arr[parent] = temp;
        index = parent;
      } else {
        break;
      }
    }
  }

  void heapifyDown(int index) {
    while (index < size) {
      int largest = index;
      int left = 2 * index + 1;
      int right = 2 * index + 2;

      if (left < size && arr[left] > arr[largest]) {
        largest = left;
      }

      if (right < size && arr[right] > arr[largest]) {
        largest = right;
      }

      if (largest != index) {
        int temp = arr[index];
        arr[index] = arr[largest];
        arr[largest] = temp;
        index = largest;
      } else {
        break;
      }
    }
  }

 public:
  PriorityQueue() {
    size = 0;
  }

  void insert(int value) {
    if (size >= 100) {
      cout << "Priority Queue is full!\n";
      return;
    }

    arr[size] = value;
    heapifyUp(size);
    size++;
    cout << "Inserted " << value << "\n";
  }

  int extractMax() {
    if (size == 0) {
      cout << "Priority Queue is empty!\n";
      return -1;
    }

    int maxVal = arr[0];
    arr[0] = arr[size - 1];
    size--;
    heapifyDown(0);

    return maxVal;
  }

  int peek() {
    if (size == 0) {
      cout << "Priority Queue is empty!\n";
      return -1;
    }
    return arr[0];
  }

  bool isEmpty() {
    return size == 0;
  }

  int getSize() {
    return size;
  }

  void display() {
    if (size == 0) {
      cout << "Priority Queue is empty!\n";
      return;
    }

    cout << "Priority Queue: ";
    for (int i = 0; i < size; i++) {
      cout << arr[i] << " ";
    }
    cout << "\n";
  }
};

int main() {
  PriorityQueue pq;
  int choice, value;

  while (true) {
    cout << "\n=== Priority Queue Menu ===\n";
    cout << "1. Insert\n";
    cout << "2. Extract Max\n";
    cout << "3. Peek\n";
    cout << "4. Display\n";
    cout << "5. Size\n";
    cout << "6. Exit\n";
    cout << "Enter choice: ";
    cin >> choice;

    switch (choice) {
      case 1:
        cout << "Enter value to insert: ";
        cin >> value;
        pq.insert(value);
        break;

      case 2:
        value = pq.extractMax();
        if (value != -1) {
          cout << "Extracted: " << value << "\n";
        }
        break;

      case 3:
        value = pq.peek();
        if (value != -1) {
          cout << "Max element: " << value << "\n";
        }
        break;

      case 4:
        pq.display();
        break;

      case 5:
        cout << "Size: " << pq.getSize() << "\n";
        break;

      case 6:
        cout << "Exiting...\n";
        return 0;

      default:
        cout << "Invalid choice!\n";
    }
  }

  return 0;
}