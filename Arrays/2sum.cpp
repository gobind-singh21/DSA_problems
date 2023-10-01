#include <bits/stdc++.h>

using namespace std;

// Brute
// TC : O(n^2)
// SC : O(1)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        for(int i = 0; i < n - 1; i++) {
            for(int j = i + 1; j < n; j++) {
                if(nums[i] + nums[j] == target)
                    return {i, j};
            }
        }
        return {-1, -1};
    }
};

// Better
// TC : O(n log n)
// SC : O(n)
class Solution1 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        map<int, int> mp;
        for(int i = 0; i < n; i++) {
            int comp = target - nums[i];
            if(mp.find(comp) == mp.end())
                mp[nums[i]] = i;
            else
                return {mp[comp], i};
        }
        return {-1, -1};
    }
};

// Optimal
// TC : O(n log n)
// SC : O(1)
class Solution3 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size(), i = 0, j = n - 1;
        while(i < j) {
            int sum = nums[i] + nums[j];
            if(sum == target)
                return {i, j};
            else if(sum < target)
                i++;
            else
                j--;
        }
        return {-1, -1};
    }
};

int main() {
    return 0;
}