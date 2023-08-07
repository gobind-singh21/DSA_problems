#include <bits/stdc++.h> 

using namespace std;

vector<int> rotateArray(vector<int>& arr, int n) {
    int firstElement = arr[0];
    for(int i = 1; i < n; i++) {
        arr[i - 1] = arr[i];
    }
    arr[n - 1] = firstElement;
    return arr;
}

int main() {
    return 0;
}