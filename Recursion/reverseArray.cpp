#include <iostream>
#include <vector>

using namespace std;

void printVector(vector<int> arr) {
    for(int i : arr)
        cout << i << ' ';
    cout << endl;
}

void reverse(vector<int> &arr, int i = 0) {
    int n = arr.size();
    if(i > n >> 1)
        return;
    int temp = arr[i];
    arr[i] = arr[n - i - 1];
    arr[n - i - 1] = temp;
    reverse(arr, i + 1);
}

vector<int> reverseFunctional(vector<int> arr, int i = 0) {
    int n = arr.size();
    if(i > n >> 1) {
        return arr;
    }
    int temp = arr[i];
    arr[i] = arr[n - i - 1];
    arr[n - i - 1] = temp;
    return reverseFunctional(arr, i + 1);
}

void reverse1(vector<int> &arr, int left, int right) {
    if(left > right)
        return;
    int temp = arr[left];
    arr[left] = arr[right];
    arr[right] = temp;
    reverse1(arr, left + 1, right - 1);
}

int main() {
    vector<int> arr = {1,2,3,4,5,6,7,8};
    printVector(arr);
    reverse(arr);
    printVector(arr);
    printVector(reverseFunctional(arr));
    return 0;
}