#include <iostream>
#include <vector>

using namespace std;

long long findncr(int n, int r) {
    long long res = 1;
    for(int i = 0; i < r; i++) {
        res *= (n - i);
        res /= (i + 1);
    }
    return res;
}

int main() {
    int r, c;
    cin >> r >> c;
    if(r == 0 && c == 0)
        cout << 1 << endl;
    else
        cout << findncr(r - 1, c - 1);
    return 0;
}