#include <iostream>
#include <vector>

using namespace std;

void printVector(vector<int> arr) {
    for(int &i : arr)
        cout << i << ' ';
    cout << endl;
}

long long findncr(int n, int r) {
    long long res = 1;
    for(int i = 0; i < r; i++) {
        res *= (n - i);
        res /= (i + 1);
    }
    return res;
}

vector<int> getRow(int r) {
    vector<int> ans;
    int element = 1;
    ans.push_back(1);
    for(int i = 1; i < r; i++) {
        element = element * (r - i);
        element = element / i;
        ans.push_back(element);
    }
    return ans;
}

int main() {
    printVector(getRow(6));
    return 0;
}