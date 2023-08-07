#include <iostream>
#include <vector>

using namespace std;

int secondLargest(vector<int> &arr) {
    int largest = INT_MIN, slargest = INT_MIN;
    for(int &i : arr) {
        if(i > largest) {
            slargest = largest;
            largest = i;
        }
        else if(i > slargest && i < largest)
            slargest = i;
    }
    return slargest;
}

int secondSmallest(vector<int> &arr) {
    int smallest = INT_MAX, ssmallest = INT_MAX;
    for(int &i : arr) {
        if(i < smallest) {
            ssmallest = smallest;
            smallest = i;
        }
        else if(i < ssmallest && i > smallest)
            ssmallest = i;
    }
    return ssmallest;
}

vector<int> getSecondOrderElements(int n, vector<int> a) {
    int slargest = secondLargest(a);
    int ssmallest = secondSmallest(a);
    vector<int> ans = {slargest, ssmallest};
    return ans;
}


int main() {
    return 0;
}