#include <iostream>

using namespace std;

void oneToN(int n) {
    if(n == 0)
        return;
    oneToN(n - 1);
    cout << n << endl;
}

void NToOne(int n) {
    if(n == 0)
        return;
    cout << n << endl;
    NToOne(n - 1);
}

int main() {
    oneToN(4);
    NToOne(4);
    return 0;
}