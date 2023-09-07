#include <bits/stdc++.h>

using namespace std;

const int mod = 1e5;

class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        if(start == end)
            return 0;
        int n = arr.size();
        vector<bool> vis(mod, false);
        queue<int> q;
        q.push(start);
        int level = 0;
        while(!q.empty()) {
            int size = q.size();
            for(int i = 0; i < size; i++) {
                int num = q.front();
                q.pop();
                for(int j = 0; j < n; j++) {
                    int nextNum = (num * arr[j]) % mod;
                    if(nextNum == end)
                        return level + 1;
                    if(!vis[nextNum]) {
                        vis[nextNum] = true;
                        q.push(nextNum);
                    }
                }
            }
            level++;
        }
        return -1;
    }
};

int main() {
    vector<int> arr = {3,4,65};
    Solution obj;
    cout << obj.minimumMultiplications(arr, 7, 66175) << endl;
    return 0;
}