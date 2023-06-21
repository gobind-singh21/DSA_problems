#include <iostream>
#include <vector>

using namespace std;

void printMat(vector<vector<string>> mat) {
    for(vector<string> temp : mat) {
        for(string str : temp)
            cout << str << endl;
        cout << endl;
    }
}

void solve(vector<string> &board, vector<vector<string>> &answer, int column, 
        vector<bool> leftColumn, vector<bool> upperRow, vector<bool> secondaryDiagonal, vector<bool> primaryDiagonal) {
    int n = board.size();
    if(column == n) {
        answer.push_back(board);
        return;
    }
    for(int i = 0; i < n; i++) {
        if(!leftColumn[i] && !upperRow[column] && !secondaryDiagonal[i + column] && !primaryDiagonal[n - 1 + column - i]) {
            board[i][column] = 'Q';
            leftColumn[i] = true;
            upperRow[column] = true;
            secondaryDiagonal[i + column] = true;
            primaryDiagonal[n - 1 + column - i] = true;
            solve(board, answer, column + 1, leftColumn, upperRow, secondaryDiagonal, primaryDiagonal);
            board[i][column] = '.';
            leftColumn[i] = false;
            upperRow[column] = false;
            secondaryDiagonal[i + column] = false;
            primaryDiagonal[n - 1 + column - i] = false;

        }
    }
}

int main() {
    int n;
    cin >> n;
    vector<string> board(n, string(n, '.'));
    vector<bool> leftColumn(n, false);
    vector<bool> upperRow(n, false);
    vector<bool> primaryDiagonal(2*n - 1, false);
    vector<bool> secondaryDiagonal(2*n - 1, false);
    vector<vector<string>> answer = {};
    solve(board, answer, 0, leftColumn, upperRow, secondaryDiagonal, primaryDiagonal);
    printMat(answer);
    return 0;
}