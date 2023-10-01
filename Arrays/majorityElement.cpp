#include <bits/stdc++.h>

using namespace std;

// Brute
// TC : O(n^2)
// SC : O(1)
// Use 2 loops and check through entire for each element

// Better
// TC : O(n log n)
// SC : O(n)
// use hashmap to store frequency of each character

// Optimal
// TC : O(n)
// SC : O(1)
// Also known as Moore's voting algorithm
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int element, cnt = 0, n = nums.size();
        for(int i = 0; i < n; i++) {
            if(cnt == 0) {
                element = nums[i];
                cnt = 1;
            }
            else if(element == nums[i])
                cnt++;
            else
                cnt--;
        }
        // If it is given that there might be a majority element then use the below
        int cnt1 = 0;
        for(int &i : nums)
            if(i == element)
                cnt1++;
        // check whether element is majority element or not
        if(cnt1 > (n >> 1))
            return element;
        // otherwise return whatever is supposed to be returned in the question
        return -1;
    }
};

int main() {
    return 0;
}