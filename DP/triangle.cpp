#include <iostream>
#include <vector>

using namespace std;

int calculateSum(vector<vector<int>> &triangle, int row, int column, vector<vector<int>> &dp) {
    if(row == triangle.size() - 1)
        return triangle[row][column];
    if(dp[row][column] != -1)
        return dp[row][column];
    int down = triangle[row][column] + calculateSum(triangle, row + 1, column, dp);
    int diagonal = triangle[row][column] + calculateSum(triangle, row + 1, column + 1, dp);
    return dp[row][column] = min(down, diagonal);
}

int minimumPathSum(vector<vector<int>>& triangle, int n){
	vector<vector<int>> dp(n, vector<int>(n, -1));
    return calculateSum(triangle, 0, 0, dp);
}

int main() {
    vector<vector<int>> triangle = {{1},{2,3},{3,6,7},{8,9,6,10}};
    cout << minimumPathSum(triangle, triangle.size()) << endl;
    return 0;
}