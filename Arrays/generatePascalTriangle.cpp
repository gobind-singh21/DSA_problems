#include <iostream>
#include <vector>

using namespace std;

class Solution {
    vector<int> generateRow(int row) {
        vector<int> ans;
        int element = 1;
        ans.push_back(1);
        for(int i = 1; i < row; i++) {
            element = element * (row - i);
            element = element / i;
            ans.push_back(element);
        }
        return ans;
    }
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        for(int i = 1; i <= numRows; i++) {
            vector<int> row = generateRow(i);
            ans.push_back(row);
        }
        return ans;
    }
};

int main() {
    return 0;
}