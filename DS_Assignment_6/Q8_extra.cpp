// 3. Given a Doubly linked list containing n nodes. The task is to reverse every group of k
// nodes in the list. If the number of nodes is not a multiple of k then left-out nodes, in the
// end should be considered as a group and must be reversed.
// https://www.geeksforgeeks.org/reverse-doubly-linked-list-groups-given-size/
// Example 1:
// Input: 1 <-> 2 <-> 3 <-> 4 <-> 5 <-> 6 <-> NULL, k = 2
// Output: 2 <-> 1 <-> 4 <-> 3 <-> 6 <-> 5 <-> NULL.
// Example 2:
// Input: 1 <-> 2 <-> 3 <-> 4 <-> 5 <-> 6 <-> NULL, k = 4
// Output: 4 <-> 3 <-> 2 <-> 1 <-> 6 -> 5 <-> NULL.