#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

class Solution {
    void bfs(vector<vector<int>> &image, int startRow, int startColumn, int newColor, int oldColor) {
        int n = image.size(), m = image[0].size();
        queue<pair<int, int>> q;
        q.push({startRow, startColumn});
        image[startRow][startColumn] = newColor;
        while(!q.empty()) {
            pair<int, int> currNode = q.front();
            int x = currNode.first, y = currNode.second;
            q.pop();
            if(x > 0 && image[x - 1][y] == oldColor) {
                q.push({x - 1, y});
                image[x - 1][y] = newColor;
            }
            if(y > 0 && image[x][y - 1] == oldColor) {
                q.push({x, y - 1});
                image[x][y - 1] = newColor;
            }
            if(x+1 < n && image[x + 1][y] == oldColor) {
                q.push({x + 1, y});
                image[x + 1][y] = newColor;
            }
            if(y+1 < m && image[x][y + 1] == oldColor) {
                q.push({x, y + 1});
                image[x][y + 1] = newColor;
            }
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color) {
        vector<vector<int>> ans = image;
        int oldColor = image[sr][sc];
        if(oldColor == color)
            return ans;
        bfs(ans, sr, sc, color, oldColor);
        return ans;
    }
};

int main() {
    
    return 0;
}