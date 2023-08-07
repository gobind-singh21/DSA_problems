#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)
            return true;
        vector<int> arr = nums;
        int counter = 0, lastIndex = n - 1;
        for(int i = 0; i < lastIndex; i++) {
            if(nums[i] > nums[i + 1])
                counter++;
        }
        if(nums[n - 1] > nums[0])
            counter++;
        
        return counter <= 1;
    }
};

int main() {
    vector<int> ar = {2,1};
    Solution obj;
    cout << obj.check(ar);
    return 0;
}