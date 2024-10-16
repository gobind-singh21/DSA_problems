#include <bits/stdc++.h>

using namespace std;

// Method 1
class Solution {
    // int solve(string &text1, string &text2, int i, int j, vector<vector<int>> &dp) {
    //     if(i == 0 || j == 0)
    //         return 0;
        
    //     if(dp[i][j] != -1)
    //         return dp[i][j];
        
    //     if(text1[i - 1] == text2[j - 1])
    //         return 1 + solve(text1, text2, i - 1, j - 1, dp);
        
    //     return max(solve(text1, text2, i - 1, j, dp), solve(text1, text2, i, j - 1, dp));
    // }
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size(), m = text2.size();
        // vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        vector<int> prev(m + 1, 0), curr(m + 1, 0);
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                if(text1[i - 1] == text2[j - 1])
                    curr[j] = 1 + prev[j - 1];
                else
                    curr[j] = max(prev[j], curr[j - 1]);
            }
            prev = curr;
        }
        return prev[m];
        // return solve(text1, text2, n, m, dp);
    }
};

// Method 2
// can also work for array of numbers as well as strings
// we can also find the longest common subsequence withing the same time complexity and same space complexity
// intuition is to map the indices elements in arr1 and then iterate over arr2 and put mapped indices in a separate array those who can't be found will be ignored
// after that find the longest LIS in the array which contains mapped indices
// size(arr1) : M, size(arr2) : N
// condition : arr1 should have distinct elements
// time complexity : O(N logN) + O(M) + O(N)
// space complexity : O(M)
class Solution2 {
    int lengthOfLIS(vector<int> &nums) {
        vector<int> ans(1, nums[0]);
        int n = nums.size();
        for(int i = 1; i < n; i++) {
            if(nums[i] > ans.back()) {
                ans.push_back(nums[i]);
            } else {
                int low = lower_bound(ans.begin(), ans.end(), nums[i]) - ans.begin();
                ans[low] = nums[i];
            }
        }
        return ans.size();
    }
public:
    int longestCommonSubsequnce(vector<int> &arr1, vector<int> &arr2) {
        unordered_map<int, int> indices;
        int m = arr1.size(), n = arr2.size();
        for(int i = 0; i < n; i++)
            indices[arr1[i]] = i;
        vector<int> mappedIndices(0);
        for(int &i : arr2) {
            unordered_map<int, int>::iterator itr = indices.find(i);
            if(itr != indices.end())
                mappedIndices.push_back(itr->second);
        }
        return lengthOfLIS(mappedIndices);
    }
};

int main() {
    return 0;
}