#include <bits/stdc++.h>

using namespace std;

// approach 1 : brute force
// pick all elements and iterate to all the elements in the array to the right side of it
// time complexity : O(n^2)
// space complexity : O(N) (in worst case but only for storing the answer and not for actually solving the problem)

// approach 2 : optimal solution
class Solution {
  public:
    vector<int> leaders(vector<int> &arr) {
        int n = arr.size();
        int lastIndex = n - 1, maxi = INT_MIN;
        vector<int> leaders(0);
        for(int i = lastIndex; i >= 0; i--) {
            if(arr[i] >= maxi) {
                maxi = arr[i];
                leaders.push_back(arr[i]);
            }
        }
        sort(leaders.begin(), leaders.end(), greater<int>());
        return leaders;
    }
};

int main() {
    return 0;
}