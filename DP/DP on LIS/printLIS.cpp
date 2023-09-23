#include <bits/stdc++.h>

using namespace std;

vector<int> printingLongestIncreasingSubsequence(vector<int> arr, int n) {
    vector<int> dp(n, 1), hash(n);
    int maxi = 1, lastIndex = 0;
    for(int i = 1; i < n; i++) {
        hash[i] = i;
        for(int prev = 0; prev < i; prev++) {
            if(arr[prev] < arr[i] && dp[i] < 1 + dp[prev]) {
                dp[i] = 1 + dp[prev];
                hash[i] = prev;
            }
        }
        if(maxi < dp[i]) {
            lastIndex = i;
            maxi = dp[i];
        }
    }   
    vector<int> ans(maxi);
    int index = maxi - 1;
    while(hash[lastIndex] != lastIndex) {
        ans[index] = arr[lastIndex];
        lastIndex = hash[lastIndex];
        index--;
    }
    ans[0] = arr[lastIndex];
    return ans;
}

void printVector(vector<int> arr) {
    for(int &i : arr)
        cout << i << ' ';
    cout << endl;
}

int main() {
    vector<int> arr = {1};
    printVector(printingLongestIncreasingSubsequence(arr, arr.size()));
    return 0;
}