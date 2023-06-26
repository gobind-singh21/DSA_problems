#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> answer;

void printVector(vector<int> arr) {
    for(int i : arr)
        cout << i << ' ';
    cout << endl;
}

void subsetSum(vector<int> input, int index, long currSum = 0) {
    if(index == input.size()) {
        answer.push_back(currSum);
        return;
    }
    subsetSum(input, index + 1, currSum);
    subsetSum(input, index + 1, currSum + input[index]);
}

int main() {
    subsetSum({2,3}, 0);
    sort(answer.begin(), answer.end());
    printVector(answer);
    return 0;
}