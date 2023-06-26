#include <iostream>
#include <vector>

using namespace std;

void printVector(vector<int> arr) {
    for(int i : arr)
        cout << i << ' ';
    cout << endl;
}

void merge(vector<int> &arr, int left, int mid, int right) {
    int i = left;
    int j = mid + 1;
    vector<int> temp;
    while(i <= mid && j <= right) {
        if(arr[i] > arr[j]) {
            temp.push_back(arr[j++]);
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
}

void mergeSort(vector<int> &arr, int left, int right) {
    if(left >= right)
        return;
    int mid = (left + right) >> 1;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}

int main() {
    vector<int> arr = {5,4,3,2,1};
    mergeSort(arr, 0, arr.size()-1);
    printVector(arr);
    return 0;
}