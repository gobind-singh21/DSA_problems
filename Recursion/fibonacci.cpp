#include <iostream>
#include <vector>

using namespace std;

vector<int> nums;

int fibonacci(int n) {
    if(n <= 1)
        return n;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int fibonacciDP(int n) {
    if(n <= 1)
        return n;
    if(nums[n] != 0)
        return nums[n];
    nums[n] = fibonacciDP(n - 1) + fibonacciDP(n - 2);
    return nums[n];
}

int main() {
    nums[0] = 0;
    nums[1] = 1;
    cout << fibonacciDP(55) << endl;
    return 0;
}