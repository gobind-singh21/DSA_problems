#include <iostream>
#include <vector>

using namespace std;

int merge(vector<int> &arr, int left, int mid, int right) {
    int i = left;
    int j = mid + 1;
    vector<int> temp;
    int ans = 0;
    while(i <= mid && j <= right) {
        if(arr[i] > arr[j]) {
            temp.push_back(arr[j++]);
            ans += (mid - i + 1);
        }
        else
            temp.push_back(arr[i++]);
    }
    while(i <= mid) {
        temp.push_back(arr[i++]);
    }
    while(j <= right) {
        temp.push_back(arr[j++]);
    }
    for(int k = left; k <= right; k++)
        arr[k] = temp[k - left];
    return ans;
}

int mergeSort(vector<int> &arr, int left, int right) {
    int ans = 0;
    if(left >= right)
        return 0;
    int mid = (left + right) >> 1;
    ans += mergeSort(arr, left, mid);
    ans += mergeSort(arr, mid + 1, right);
    ans += merge(arr, left, mid, right);
    return ans;
}

int numberOfInversions(vector<int> &a, int n) {
    return mergeSort(a, 0, n - 1);
}

int main() {
    return 0;
}