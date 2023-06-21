#include <iostream>
#include <vector>

using namespace std;

void printMatrix(vector<int> arr) {
    for(int i : arr)
        cout << i << ' ';
    cout << endl;
}

void subSequence(vector<int> arr, vector<int> temp = {}, int i = 0) {
    if(i == arr.size()) {
        if(!temp.empty())
            printMatrix(temp);
        return;
    }
    subSequence(arr, temp, i + 1);
    temp.push_back(arr[i]);
    subSequence(arr, temp, i + 1);
}

int main() {
    subSequence({3,2,1});
    return 0;
}