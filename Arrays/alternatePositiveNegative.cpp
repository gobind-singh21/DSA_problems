#include <bits/stdc++.h>

using namespace std;

class Solution {
public:

  // Time complexity: O(n)
  // Space complexity: O(n)
  vector<int> rearrangeArray(vector<int>& nums) {
    int n = nums.size();

    vector<int> negatives(n >> 1, 0), positives(n >> 1, 0), result(n, 0);
    unsigned int negative_index = 0, positive_index = 0;
    for(const int &i : nums) {
      negatives[negative_index] = i;
      negative_index += i < 0;
      positives[positive_index] = i;
      positive_index += i >= 0;
    }
    return result;
  }

  // Time complexity: O(n)
  // Space complexity: O(1)
  vector<int> rearrangeArray1(vector<int> &nums) {
    const size_t n = nums.size();

    vector<int> result(n);

    size_t positive_index = 0, negative_index = 1;
    for(const int &i: nums) {
      if(i >= 0) {
        result[positive_index] = i;
        positive_index += 2;
      } else {
        result[negative_index] = i;
        negative_index += 2;
      }
    }

    return result;
  }
};

void printVector(vector<int> arr) {
  for(const int &i : arr)
    cout << i << ' ';
  cout << endl;
}

int main() {
  vector<int> arr = {1, 2, -1};
  Solution obj;
  printVector(obj.rearrangeArray1(arr));
  return 0;
}