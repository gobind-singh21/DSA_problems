#include <bits/stdc++.h>

using namespace std;

// only one approach
// time complexity : O(n * m) because we are iterating to all the elements in the array
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<int> order(0);
        int left = 0, top = 0, right = m - 1, bottom = n - 1;
        while(left <= right && top <= bottom) {
            for(int i = left; i <= right; i++)
                order.push_back(matrix[top][i]);
            top++;
            for(int i = top; i <= bottom; i++)
                order.push_back(matrix[i][right]);
            right--;
            if(top <= bottom) {
                for(int i = right; i >= left; i--)
                    order.push_back(matrix[bottom][i]);
                bottom--;
            }
            if(left <= right) {
                for(int i = bottom; i >= top; i--)
                    order.push_back(matrix[i][left]);
                left++;
            }
        }
        return order;
    }
};

int main() {
    return 0;
}