#include <iostream>
#include <vector>

using namespace std;

long long int tabulation(vector<int> &nums) {
    long long int prev2 = 0, prev = nums[0], curri;
    int n = nums.size();
    for(int i = 1; i < n; i++) {
        int take = nums[i];
        if(i > 1)
            take += prev2;
        int nonTake = prev;
        curri = take > nonTake ? take : nonTake;
        prev2 = prev;
        prev = curri;
    }
    return prev;
}

long long int houseRobber(vector<int> &valueInHouse) {
    int n = valueInHouse.size();
    if(n == 1)
        return valueInHouse[0];
    vector<int> arr1, arr2;
    for(int i = 0; i < n; i++) {
        if(i != 0)
            arr1.push_back(valueInHouse[i]);
        if(i != n - 1)
            arr2.push_back(valueInHouse[i]);
    }
    return max(tabulation(arr1), tabulation(arr2));
}

int main() {
    return 0;
}