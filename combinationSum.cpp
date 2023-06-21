#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> answer(0);

void printMatrix(vector<vector<int>> arr) {
    for(vector<int> temp : arr) {
        for(int i : temp)
            cout << i << ' ';
        cout << endl;
    }
}

void combinationSum(vector<int> input, int currIndex, int target, vector<int> currCombination = {}) {
    if(target == 0) {
        answer.push_back(currCombination);
        return;
    }
    if(currIndex == input.size() || target < 0)
        return;
    combinationSum(input, currIndex + 1, target, currCombination);
    currCombination.push_back(input[currIndex]);
    combinationSum(input, currIndex, target - input[currIndex], currCombination);
}

int main() {
    combinationSum({2,3,6,7}, 0, 7);
    printMatrix(answer);
    return 0;
}