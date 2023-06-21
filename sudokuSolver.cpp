#include <iostream>
#include <vector>

using namespace std;

void printMat(vector<vector<char>> input) {
    for(vector<char> temp : input) {
        for(char ch : temp)
            cout << ch << ' ';
        cout << endl;
    }
}

bool isValid(vector<vector<char>> &input, int row, int column, char ch) {
    for(int i = 0; i < 9; i++) {
        if(input[row][i] == ch || input[i][column] == ch || input[3*(row / 3) + i / 3][3*(column / 3) + i % 3] == ch)
            return false;
    }
    return true;
}

bool solve(vector<vector<char>> &input, int row, int column) {
    for(int i = 0; i < 9; i++) {
        for(int j = 0; j < 9; j++) {
            if(input[i][j] == '.') {
                for(char ch = '1'; ch <= '9'; ch++) {
                    if(isValid(input, i, j, ch)) {
                        input[i][j] = ch;
                        if(solve(input, i, j))
                            return true;
                        else
                            input[i][j] = '.';
                    }
                }
                return false;
            }
        }
    }
    return true;
}

int main() {
    vector<vector<char>> input = {{'5','3','.','6','7','8','9','.','2'}, 
                                  {'6','7','2','1','9','5','3','4','8'},
                                  {'.','9','8','3','4','2','5','6','7'},
                                  {'8','5','9','7','6','1','4','2','3'},
                                  {'4','2','6','8','5','3','7','9','1'},
                                  {'7','1','3','9','.','4','8','5','6'},
                                  {'9','6','.','5','3','7','2','8','4'},
                                  {'2','8','7','4','1','9','6','3','5'},
                                  {'3','4','5','2','8','6','1','7','9'}};
    solve(input, 0, 0);
    printMat(input);
    return 0;
}