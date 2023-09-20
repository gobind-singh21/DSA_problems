#include <bits/stdc++.h>

using namespace std;

int iterative(vector<int> &arr, int &target) {
    int start = 0, end = arr.size() - 1;
    while(start <= end) {
        int mid = start + ((end - start) >> 1);
        if(arr[mid] == target)
            return mid;
        else if(arr[mid] < target)
            start = mid + 1;
        else
            end = mid - 1;
    }
    return -1;
}

int recursive(vector<int> &arr, int &target, int start, int end) {
    int mid = start + ((end - start) >> 1);
    if(arr[mid] == target)
        return mid;
    else if(arr[mid] < target)
        return recursive(arr, target, mid + 1, end);
    return recursive(arr, target, start, mid - 1);
}

int main() {
    return 0;
}