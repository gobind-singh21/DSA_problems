#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // brute force :
    // time complexity : O(N! * N)

    // better/optimal: (only for C++)
    vector<int> nextGreaterPermutationBetter(vector<int> &A) {
        next_permutation(A.begin(), A.end());
        return A;
    }

    // better/optimal : (impplementing that next_permutation)
    vector<int> nextGreaterPermutationOptimal(vector<int> &A) {
        int n = A.size(), lastIndex = n - 1, breakPoint = -1;
        for(int i = 0; i < lastIndex; i++) {
            if(A[i] < A[i + 1]) {
                breakPoint = i;
                break;
            }
        }
        if(breakPoint == -1) {
            sort(A.begin(), A.end());
            return A;
        }
        for(int i = lastIndex; i > breakPoint; i--) {
            if(A[i] > A[breakPoint]) {
                swap(A[i], A[breakPoint]);
                break;
            }
        }
        sort(A.begin() + breakPoint + 1, A.end());
        return A;
    }
};

int main() {
    vector<int> A = {2, 1, 5, 4, 3, 0, 0};
    A = Solution().nextGreaterPermutationOptimal(A);
    for(int &i : A)
        cout << i << ' ';
    cout << endl;
    return 0;
}