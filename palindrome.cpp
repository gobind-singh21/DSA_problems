#include <iostream>

using namespace std;

bool checkPalindrome(string str, int i = 0) {
    int n = str.size();
    if(i > n >> 1)
        return true;
    if(str[i] != str[n - i - 1])
        return false;
    return checkPalindrome(str, i + 1);
}

int main() {
    cout << checkPalindrome("abb");
    return 0;
}