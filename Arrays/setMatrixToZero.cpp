#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // matrix dimension : n x m

    // brute force:
    // iterate over entire matrix and mark columns and rows of all zeros with -1
    // then replace all the -1 in the matrix with 0
    // time complexity : O(n * m) * O(n + m) + O(n * m)
    // space complexity : O(1)

    // better:
    // time complexity : O(n * m) + O(n * m)
    // space complexity : O(n + m)
    void setZeroesBetter(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<bool> columnHasZero(m, false), rowHasZero(n, false);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(matrix[i][j] == 0)
                    columnHasZero[j] = rowHasZero[i] = true;
            }
        }
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(columnHasZero[j] || rowHasZero[i])
                    matrix[i][j] = 0;
            }
        }
    }

    // optimal
    // time complexity : O()
    // space complexity : O()
    void setZeroesOptimal(vector<vector<int>> &matrix) {
        int n = matrix.size(), m = matrix[0].size();
        int col0 = 1;
        for (int i = 1; i < n; i++) {
            for(int j = 1; j < m; j++) {
                
            }
        }
        
    }
};

int main() {
    return 0;
}