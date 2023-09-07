#include <iostream>
#include <vector>

using namespace std;

int largestElement(vector<int> &arr, int n) {
    int ans = arr[0];
    for(int i = 1; i < n; i++)
        if(arr[i] > ans)
            ans = arr[i];
    return ans;
}

int main() {
    return 0;
}