// problem description:
// there is an array of size N with N/2 +ve elements and N/2 -ve elements
// re arrange all the array elements such that +ve and -ve elements come in alternatively
// while keeping relative ordering of +ve and -ve elements

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // Brute force
    // time complexity : O(N) + O(N/2)
    // space complexity : O(N) + O(N) (for storing +ve and -ve and then answer)
    vector<int> alternateNumbersBrute(vector<int> &elements) {
        int n = elements.size(), half = n >> 1;
        vector<int> positives(0), negatives(0);
        for(int &i : elements) {
            if(i < 0)
                negatives.push_back(i);
            else
                positives.push_back(i);
        }
        vector<int> answer(0);
        for(int i = 0; i < n; i++) {
            answer.push_back(positives[i]);
            answer.push_back(negatives[i]);
        }
        return answer;
    }

    // Optimal
    // time complexity : O(N)
    // space complexity : O(N) (only for answer array)
    vector<int> alternateNumbersOptimal(vector<int> &elements) {
        int n = elements.size();
        vector<int> answer(n);
        int positiveIndex = 0, negativeIndex = 1;
        for(int &i : elements) {
            if(i > 0) {
                answer[positiveIndex] = i;
                positiveIndex += 2;
            } else {
                answer[negativeIndex] = i;
                negativeIndex += 2;
            }
        }
        return answer;
    }
};

// variety 2:
// number of -ve is not equal to number of +ve
class SolutionAlternate {
public:

    // time complexity : O(N) + O(N)
    // space complexity : O(2N) (for storing the elements and the answer)
    vector<int> alternateNumbers(vector<int> &nums) {
        int n = nums.size();
        vector<int> negatives(0), positives(0);
        vector<int> ans(0);
        for(int &i : nums) {
            if(i < 0)
                negatives.push_back(i);
            else
                positives.push_back(i);
        }
        int pn = positives.size(), nn = n - pn;
        int i = 0, j = 0;
        while(i < pn && j < nn) {
            ans.push_back(positives[i]);
            i++;
            ans.push_back(negatives[j]);
            j++;
        }
        while(i < pn) {
            ans.push_back(positives[i]);
            i++;
        }
        while(j < nn) {
            ans.push_back(negatives[j]);
            j++;
        }

        return ans;
    }
};

int main() {
    return 0;
}