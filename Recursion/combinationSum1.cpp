#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> answer(0);

void printMatrix(vector<vector<int>> arr) {
    for(vector<int> temp : arr) {
        for(int i : temp)
            cout << i << ' ';
        cout << endl;
    }
}

void combinationSum(vector<int> input, int index, int target, vector<int> currCombination = {}) {
    if(target == 0) {
        answer.push_back(currCombination);
        return;
    }
    for(int i = index; i < input.size(); i++) {
        if(i > index && input[i] == input[i - 1])
            continue;
        if(input[i] > target)
            break;
        currCombination.push_back(input[i]);
        combinationSum(input, i + 1, target - input[index], currCombination);
        currCombination.pop_back();
    }
}

int main() {
    vector<int> arr = {10, 1, 2, 7, 6, 1, 5};
    sort(arr.begin(), arr.end());
    
    combinationSum(arr, 0, 8);
    printMatrix(answer);
    return 0;
}