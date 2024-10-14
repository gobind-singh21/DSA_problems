#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // brute approach
    // time complexity : O(n^3)
    // space complexity : O(1)
    int maxSubArrayBrute(vector<int>& nums) {
        int n = nums.size();
        int maxi = INT_MIN;
        for(int i = 0; i < n; i++) {
            for(int j = i; j < n; j++) {
                int sum = 0;
                for(int k = i; k <= j; k++)
                    sum += nums[k];
                if(maxi < sum)
                    maxi = sum;
            }
        }
        return maxi;
    }

    // better approach
    // time complexity : O(n^2)
    // space complexity : O(1)
    int maxSubArrayBetter(vector<int> &nums) {
        int n = nums.size();
        int maxi = INT_MIN;
        for(int i = 0; i < n; i++) {
            int sum = 0;
            for(int j = i; j < n; j++) {
                sum += nums[j];
            }
            if(maxi < sum)
                maxi = sum;
        }
        return maxi;
    }

    // optimal approach
    // time complexity : O(n)
    // space complexity : O(1)
    // also known as **KADANE'S ALGO**
    int maxSubArrayOptimal(vector<int> &nums) {
        int n = nums.size();
        int maxi = INT_MIN;
        int sum = 0;
        for(int i = 0; i < n; i++) {
            sum += nums[i];
            maxi = max(sum, maxi);
            if(sum < 0)
                sum = 0;
        }
        return maxi;
    }
};

int main() {
    return 0;
}