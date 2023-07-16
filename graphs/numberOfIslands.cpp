#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void isIsland(vector<vector<char>> &grid, int x, int y) {
        if(x < 0 || y < 0 || x >= grid.size() || y >= grid[0].size() || grid[x][y] == '0')
            return ;
        grid[x][y] = '0';
        isIsland(grid, x - 1, y);
        isIsland(grid, x + 1, y);
        isIsland(grid, x, y - 1);
        isIsland(grid, x, y + 1);
    }
    int numIslands(vector<vector<char>>& grid) {
        int answer = 0, m = grid.size(), n = grid[0].size();
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == '1') {
                    isIsland(grid, i, j);
                    answer++;
                }
            }
        }
        return answer;
    }
};

int main() {
    return 0;
}