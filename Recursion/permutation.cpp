#include <iostream>
#include <vector>

using namespace std;

void printMatrix(vector<vector<int>> mat) {
    for(vector<int> temp : mat) {
        for(int i : temp)
            cout << i << ' ';
        cout << endl;
    }
}

void permutation(vector<int> &integers, vector<vector<int>> &answer, vector<bool> visited, vector<int> currCombination = {}) {
    int n = integers.size();
    if(currCombination.size() == n) {
        answer.push_back(currCombination);
        return;
    }
    for(int i = 0; i < n; i++) {
        if(visited[i])
            continue;
        visited[i] = true;
        currCombination.push_back(integers[i]);
        permutation(integers, answer, visited, currCombination);
        currCombination.pop_back();
        visited[i] = false;
    }
}

int main() {
    vector<vector<int>> answer(0);
    vector<int> integers = {1,2,4};
    vector<bool> visited(integers.size(), false);
    permutation(integers, answer, visited);
    printMatrix(answer);
    return 0;
}