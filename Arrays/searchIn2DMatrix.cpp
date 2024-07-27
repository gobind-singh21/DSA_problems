#include<bits/stdc++.h>

using namespace std;

// Matrix : n x m
// Approach 1 : linear search
// Time complexity : O(n x m)
// Space complexity : O(1)

// Approach 2 : Check range for every row to decide whether element is there or not
// go to every row check first and last element to check whether that element is there in that row or not
// Time complexity : O(n log(m))
// space complexity : O(1)

// Approach 3 : Flatten the entire 2d array hypothetically and then apply binary search on the entire 2d array
// Time complexity : O(log(n x m))
// space complexity : O(1)

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(), m = matrix[0].size();
        int left = 0, right = n * m - 1;
        while(left <= right) {
            int mid = ((right - left) >> 1) + left;
            int row = mid / m, col = mid % m;
            cout << mid << ' ' << row << ' ' << col << ' ' << matrix[row][col] << endl;
            if(matrix[row][col] == target)
                return true;
            else if (matrix[row][col] > target)
                right = mid - 1;
            else
                left = mid + 1;
        }
        return false;
    }
};

int main() {
    Solution obj;
    vector<vector<int>> arr = {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};
    cout << obj.searchMatrix(arr, 3) << endl;
    return 0;
}