#include <iostream>
#include <vector>

using namespace std;

class Solution {
    inline bool isValid(vector<vector<char>> &board, vector<vector<bool>> &vis, int &r, int &c, int &n, int &m) {
        return r >= 0 && r < n && c >= 0 && c < m && board[r][c] == 'O' && !vis[r][c];
    }

    void dfs(vector<vector<char>> &board, vector<vector<bool>> &visited, int row, int column, int &n, int &m) {
        int dRow[] = {1, 0, -1, 0};
        int dCol[] = {0, -1, 0, 1};
        for(int i = 0; i < 4; i++) {
            int nRow = row + dRow[i], nCol = column + dCol[i];
            if(isValid(board, visited, nRow, nCol, n, m)) {
                visited[nRow][nCol] = true;
                dfs(board, visited, nRow, nCol, n, m);
            }
        }
    }

    void markO(vector<vector<char>> &board, vector<vector<bool>> &visited, int &n, int &m) {
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                if(!visited[i][j] && board[i][j] == 'O')
                    board[i][j] = 'X';
    }
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size(), m = board[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        for(int i = 0; i < n; i++) {
            if(board[i][0] == 'O' && !visited[i][0]) {
                visited[i][0] = true;
                dfs(board, visited, i, 0, n, m);
            }
            if(board[i][m - 1] == 'O' && !visited[i][m - 1]) {
                visited[i][m - 1] = true;
                dfs(board, visited, i, m - 1, n, m);
            }
        }

        for(int i = 0; i < m; i++) {
            if(board[0][i] == 'O' && !visited[0][i]) {
                visited[0][i] = true;
                dfs(board, visited, 0, i, n, m);
            }
            if(board[n - 1][i] == 'O' && !visited[n - 1][i]) {
                visited[n - 1][i] = true;
                dfs(board, visited, n - 1, i, n, m);
            }
        }

        markO(board, visited, n, m);
    }
};

int main() {
    return 0;
}