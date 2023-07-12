#include <iostream>
#include <vector>

using namespace std;

string getPermutation(int n, int k) {
    int fact = 1;
    vector<int> numbers(0);
    for(int i = 1; i < n; i++) {
        fact *= i;
        numbers.push_back(i);
    }
    numbers.push_back(n);
    string ans = "";
    k--;
    while(true) {
        ans += to_string(numbers[k / fact]);
        numbers.erase(numbers.begin() + k / fact);
        if(numbers.size() == 0)
            break;
        k %= fact;
        fact /= numbers.size();
    }
    return ans;
}

int main() {
    return 0;
}