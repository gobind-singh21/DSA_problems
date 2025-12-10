#include <bits/stdc++.h>

using namespace std;

int longestSubArray(vector<int> &arr, int k) {
  unordered_map<int, int> mp;

  int sum = 0;
  size_t n = arr.size(), max_size = 0;

  for(size_t i = 0; i < n; i++) {
    sum += arr[i];

    max_size = sum == k && max_size < i + 1 ? i + 1 : max_size;

    int rem = k - sum;
    unordered_map<int, int>::iterator it = mp.find(rem);
    const int position = it != mp.end() ? (*it).second : -1;

    max_size = position != -1 && max_size < i - position ? i - position : max_size;
    mp[sum] = position == -1 ? i : position;
  }

  return max_size;
}

int main() {
  vector<int> arr = {10, -3, 4, 5, 6, -20, 3};
  const int k = 22;

  printf("%d\n", longestSubArray(arr, k));

  return 0;
}