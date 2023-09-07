#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // TC : O(n * n)
    // SC : O(1)
    int missingNumberBrute(vector<int> &nums) {
        int n = nums.size();
        for(int i = 0; i <= n; i++) {
            int flag = 0;
            for(int j = 0; j < n; j++) {
                if(nums[j] == i) {
                    flag = 1;
                    break;
                }
            }
            if(flag == 0)
                return i;
        }
        return -1;
    }

    // TC : O(2n)
    // SC : O(n)
    int missingNumberBetter(vector<int> &nums) {
        int n = nums.size();
        vector<bool> temp(n + 1, false);
        for(int &i : nums)
            temp[i] = true;
        for(int i = 0; i <= n; i++)
            if(!temp[i])
                return i;
        return -1;
    }

    // TC : O(n)
    // SC : O(1)
    int missingNumberOptimal(vector<int>& nums) {
        int n = nums.size();
        int sum = 0, expected = (n *(n + 1)) >> 1;
        for(int &i : nums)
            sum += i;
        int missing = expected - sum;
        return missing;
    }

    // better than previous because int sum can overflow for large input
    // TC : O(n)
    // SC : O(1)
    int missingNumberOptimal1(vector<int> &nums) {
        int n = nums.size(), xor1 = 0, xor2 = 0;
        for(int i = 0; i < n; i++) {
            xor1 ^= nums[i];
            xor2 ^= i;
        }
        xor2 ^= n;
        return xor1 ^ xor2;
    }
};

int main() {
    return 0;
}