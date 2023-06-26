#include <iostream>
#include <vector>

using namespace std;

void printVector(vector<int> arr) {
    for(int i : arr)
        cout << i << ' ';
    cout << endl;
}

bool subSequence(vector<int> arr, int k, vector<int> temp = {}, int index = 0, int currSum = 0) {
    if(index == arr.size()) {
        if(currSum == k)
            if(!temp.empty()) {
                printVector(temp);
                return true;
            }
        return false;
    }
    if(subSequence(arr, k, temp, index + 1, currSum)) {
        return true;
    }
    temp.push_back(arr[index]);
    return subSequence(arr, k, temp, index + 1, currSum + arr[index]);
}

int main() {
    subSequence({1,2,0,-1},2);
    return 0;
}