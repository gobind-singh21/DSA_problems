#include <bits/stdc++.h>

using namespace std;

// Brute
// just use regular sorting algo

// Better
// count number of 0, 1, 2 and insert them afterwards on the basis of their count

// Optimal
// TC : O(n)
// SC : O(1)
// Also known as dutch national flag algorithm
class Solution {
public:
    void sortColors(vector<int>& arr) {
        int low = 0, mid = 0, high = arr.size() - 1;
        while(mid <= high) {
            if(arr[mid] == 0) {
                swap(arr[low], arr[mid]);
                mid++;
                low++;
            }
            else if(arr[mid] == 1)
                mid++;
            else {
                swap(arr[high], arr[mid]);
                high--;
            }
        }
    }
};

int main() {
    return 0;
}