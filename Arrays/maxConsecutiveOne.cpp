#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int counter = 0, maxi = 0;
        for(int &i : nums) {
            if(i == 1)
                counter++;
            else {
                maxi = max(maxi, counter);
                counter = 0;
            }
        }
        maxi = max(maxi, counter);
        return maxi;
    }
};

int main() {
    return 0;
}