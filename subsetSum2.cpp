#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> answer(0);

void printMatrix(vector<vector<int>> arr) {
    for(vector<int> i : arr) {
        for(int j : i)
            cout << j << ' ';
        cout << endl;
    }
}

void subsetSum2(vector<int> &input, int index = 0, vector<int> currCombination = {}) {
    int n = input.size();
    for(int i = index; i < n; i++) {
        if(i > index && input[i] == input[i - 1])
            continue;
        currCombination.push_back(input[i]);
        answer.push_back(currCombination);
        subsetSum2(input, i + 1, currCombination);
        currCombination.pop_back();
    }

}

int main() {
    vector<int> input = {1,2,2,2,3,3};
    subsetSum2(input);
    printMatrix(answer);
    return 0;
}