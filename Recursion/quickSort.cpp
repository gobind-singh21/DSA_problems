#include <iostream>
#include <vector>

using namespace std;

void printVector(vector<int> arr) {
    for(int i : arr)
        cout << i << ' ';
    cout << endl;
}

int function(vector<int> &arr, int low, int high) {
    int point = arr[low];
    int i = low, j = high;
    while(i < j) {
        while(arr[i] <= point && i <= high - 1)
            i++;
        while(arr[j] > point && j >= low + 1)
            j--;
        if(i < j)
            swap(arr[i], arr[j]);
    }
    swap(arr[low], arr[j]);
    return j;
}

void quickSort(vector<int> &arr, int low, int high) {
    if(low < high) {
        // cout << low << ' ' << high << endl;
        int pivot = function(arr, low, high);
        quickSort(arr, low, pivot - 1);
        quickSort(arr, pivot + 1, high);
    }
}

int main() {
    vector<int> arr = {5,4,3,2,1};
    quickSort(arr, 0, arr.size() - 1);
    printVector(arr);
    return 0;
}