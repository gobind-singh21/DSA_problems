#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // better :
    // sort the array then look for consecutive numbers
    int longestSuccessiveElements(vector<int> &a) {
        sort(a.begin(), a.end());
        int n = a.size(), lastSmall = INT_MIN, currCount = 1, maxLength = 1;
        for(int &i : a) {
            if(i == lastSmall + 1) {
                lastSmall = i;
                currCount++;
                maxLength = max(maxLength, currCount);
            } else if(i != lastSmall) {
                lastSmall = i;
                currCount = 1;
            }
        }
        return maxLength;
    }
};

int main() {
    vector<int> a = {101, 100, 1, 103, 4, 2, 3};
    cout << Solution().longestSuccessiveElements(a) << endl;
    return 0;
}