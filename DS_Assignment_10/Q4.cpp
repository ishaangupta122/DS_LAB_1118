// 4. Find the first non-repeating element in an array using a hash map.
// Input:
// [4, 5, 1, 2, 0, 4]
// Output:
// 5

#include <iostream>
#include <unordered_map>
using namespace std;

int firstNonRepeating(int nums[], int n) {
  unordered_map<int, int> freq;

  for (int i = 0; i < n; i++) {
    freq[nums[i]]++;
  }

  // Find first non-repeating element
  for (int i = 0; i < n; i++) {
    if (freq[nums[i]] == 1) {
      return nums[i];
    }
  }

  return -1;
}

int main() {
  int nums[] = {4, 5, 1, 2, 0, 4};
  int n = 6;

  cout << "Input: ";
  for (int i = 0; i < n; i++) {
    cout << nums[i] << " ";
  }
  cout << "\n";

  int result = firstNonRepeating(nums, n);

  if (result != -1) {
    cout << "Output: " << result << "\n";
  } else {
    cout << "Output: No non-repeating element found\n";
  }

  return 0;
}
