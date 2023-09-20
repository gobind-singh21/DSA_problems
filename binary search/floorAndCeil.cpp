#include <bits/stdc++.h>

using namespace std;

int findFloor(vector<int> &arr, int &n, int &x) {
    int start = 0, end = n - 1, ans = -1;
    while(start <= end) {
        int mid = start + ((end - start) >> 1);
        if(arr[mid] == x)
            return ans = arr[mid];
        if(arr[mid] < x) {
            ans = arr[mid];
            start = mid + 1;
        }
        else
            end = mid - 1;
    }
    return ans;
}

int findCeil(vector<int> &arr, int &n, int &x) {
    int start = 0, end = n - 1, ans = -1;
    while(start <= end) {
        int mid = start + ((end - start) >> 1);
        if(arr[mid] == x)
            return ans = arr[mid];
        if(arr[mid] > x) {
            ans = arr[mid];
            end = mid - 1;
        }
        else
            start = mid + 1;
    }
    return ans;
}

pair<int, int> getFloorAndCeil(vector<int> &arr ,int n, int x) {
    sort(arr.begin(), arr.end());
    int f = findFloor(arr, n, x);
    int c = findCeil(arr, n, x);
    return {f, c};
}

int main() {
    return 0;
}