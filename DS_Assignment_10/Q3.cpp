// 3. Count the frequency of each number in an array using a hash map.
// Input:
// nums = [2, 3, 2, 4, 3, 2]
// Output:
// • 2 → 3 times
// • 3 → 2 times
// • 4 → 1 time

#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
  int nums[] = {2, 3, 2, 4, 3, 2};
  int n = 6;

  cout << "Input: ";
  for (int i = 0; i < n; i++) {
    cout << nums[i] << " ";
  }
  cout << "\n";

  unordered_map<int, int> freq;

  for (int i = 0; i < n; i++) {
    freq[nums[i]]++;
  }

  cout << "Output:\n";
  for (auto& pair : freq) {
    cout << pair.first << ": " << pair.second << " time\n";
  }

  return 0;
}
