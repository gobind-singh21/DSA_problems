#include <bits/stdc++.h>

using namespace std;

// Optimal approach
// Time complexity : O(n)
// Space complexity : O(1)
// 2 pointer approach
int largestSubArray(vector<int> &arr, int k) {
  int n = arr.size();
  int start = 0, end = 0;
  int sum = 0;

  int max_size = 0;

  while(end < n) {
    sum += arr[end++];
    while(sum > k && start < end)
      sum -= arr[start++];
    max_size = (end - start + 1) > max_size ? end - start + 1 : max_size;
  }

  return max_size;
}

int main() {
  return 0;
}