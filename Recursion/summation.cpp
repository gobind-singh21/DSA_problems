#include <iostream>

using namespace std;

void parameterized(int n, int sum = 0) {
    if(n < 1) {
        cout << sum << endl;
        return;
    }
    parameterized(n - 1, sum + n);
}

int functional(int n) {
    if(n == 1)
        return 1;
    return functional(n - 1) + n;
}

int main() {
    int n;
    cin >> n;
    parameterized(n);
    cout <<  functional(n) << endl;
    return 0;
}