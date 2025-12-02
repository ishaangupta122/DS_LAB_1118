// 2. Given two arrays, find the common elements using a hash set.
// Input:
// A = [1, 2, 3, 4]
// B = [3, 4, 5, 6]
// Output:
// 3, 4

#include <iostream>
#include <unordered_set>
using namespace std;

void findCommonElements(int A[], int n1, int B[], int n2) {
  unordered_set<int> setA;

  for (int i = 0; i < n1; i++) {
    setA.insert(A[i]);
  }

  cout << "Output (Common Elements): ";
  bool first = true;

  for (int i = 0; i < n2; i++) {
    if (setA.find(B[i]) != setA.end()) {
      if (!first) {
        cout << ", ";
      }
      cout << B[i];
      first = false;
    }
  }
  cout << "\n";
}

int main() {
  int A[] = {1, 2, 3, 4};
  int B[] = {3, 4, 5, 6};
  int n1 = 4;
  int n2 = 4;

  cout << "Input:\n";
  cout << "A = ";
  for (int i = 0; i < n1; i++) {
    cout << A[i] << " ";
  }
  cout << "\n";

  cout << "B = ";
  for (int i = 0; i < n2; i++) {
    cout << B[i] << " ";
  }
  cout << "\n";

  findCommonElements(A, n1, B, n2);

  return 0;
}
