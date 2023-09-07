#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // for right rotation

    // better
    // TC : O(n + d)
    // SC : O(d)
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        if(k % n == 0)
            return;
        k %= n;
        vector<int> temp(k);
        for(int i = n - k; i < n; i++)
            temp[i - n + k] = nums[i];
        for(int i = n - k - 1; i >= 0; i--)
            nums[i + k] = nums[i];
        for(int i = 0; i < k; i++)
            nums[i] = temp[i];
    }

    // optimal
    // TC : O(2n)
    // SC : O(1)
    void rotate1(vector<int>& nums, int k) {
        int n = nums.size();
        if(k % n == 0)
            return;
        k %= n;
        reverse(nums.begin(), nums.begin() + n - k);    // O(n - k)
        reverse(nums.begin() + n - k, nums.end());      // O(k)
        reverse(nums.begin(), nums.end());              // O(n)
    }

    // for left rotation
    // better
    void rotate2(vector<int> &nums, int k) {
        int n = nums.size();
        if(k % n == 0)
            return;
        k %= n;
        vector<int> temp(k);
        for(int i = 0; i < k; i++)
            temp[i] = nums[i];
        for(int i = k; i < n; i++)
            nums[i - k] = nums[i];
        for(int i = n - k; i < n; i++)
            nums[i] = temp[i - n + k];
    }

    // optimal
    void rotate3(vector<int> &nums, int k) {
        int n = nums.size();
        if(k % n == 0)
            return;
        k %= n;
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
        reverse(nums.begin(), nums.end());
    }
};

int main() {
    return 0;
}