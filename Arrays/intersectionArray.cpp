#include <bits/stdc++.h>

using namespace std;

// Brute
// TC : O(n * m) for worst case
// SC : O(m)
vector<int> findArrayIntersection(vector<int> &arr1, int n, vector<int> &arr2, int m) {
	vector<int> ans;
    vector<bool> vis(m, false);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(arr1[i] == arr2[j] && !vis[j]) {
                ans.push_back(arr1[i]);
                vis[j] = true;
                break;
            }
            if(arr2[j] > arr1[i])
                break;
        }
    }
    return ans;
}

// optimal
// TC : O(n + m)
// SC : O(1)
vector<int> findArrayIntersection1(vector<int> &arr1, int n, vector<int> &arr2, int m) {
    int i = 0, j = 0;
    vector<int> ans;
    while(i < n && j < m) {
        if(arr1[i] < arr2[j])
            i++;
        else if(arr1[i] > arr2[j])
            j++;
        else {
            ans.push_back(arr1[i]);
            i++;
            j++;
        }
    }
    return ans;
}

int main() {
    return 0;
}