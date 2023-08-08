#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // brute
    // TC : O(n) + O(n - x) + O(x) = O(2n)
    // SC : O(x) worst case : O(n)
    // x -> number of non zeros element
    // n -> number of elements in array
    void moveZeroes(vector<int>& nums) {
        vector<int> temp;
        for(int &i : nums)
            if(i != 0)
                temp.push_back(i);
        
        int x = temp.size(), n = nums.size();
        for(int i = 0; i < x; i++)
            nums[i] = temp[i];
        for(int i = x; i < n; i++)
            nums[i] = 0;
    }

    // optimal
    // TC : O(x) + O(n - x) = O(n)
    // SC : O(1)
    // x -> position of first zero
    void moveZeroes1(vector<int> &nums) {
        int j = 0, n = nums.size(), i = 0;
        while(j < n && nums[j] != 0)
            j++;
        i = j + 1;
        while(i < n) {
            if(nums[i] == 0)
                i++;
            else {
                swap(nums[j], nums[i]);
                i++;
                j++;
            }
        }
    }
};

int main() {
    return 0;
}