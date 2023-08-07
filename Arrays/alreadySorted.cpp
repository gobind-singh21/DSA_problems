#include <iostream>
#include <vector>

using namespace std;

int isSorted(int n, vector<int> a) {
    int lastIndex = n - 1;
    for(int i = 0; i < lastIndex; i++) {
        int nextIndex = i + 1;
        if(a[i] > a[nextIndex])
            return 0;
    }
    return 1;
}

int main() {
    return 0;
}