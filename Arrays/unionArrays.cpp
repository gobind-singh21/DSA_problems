#include <bits/stdc++.h>

using namespace std;

// brute
// TC : O(n1 log n1 + n2 log n2) + O(n1 + n2)
// SC : O(n1 + n2) + O(n1 + n2)(used to return the answer)
// n1 -> size of a, n2 -> size of b
// log n due to set insertion
vector <int> sortedArray(vector <int> a, vector <int> b) {
    set<int> st;
    for(int &i : a)
        st.insert(i);
    for(int &i : b)
        st.insert(i);
    vector<int> ans;
    for(auto &i : st)
        ans.push_back(i);
    return ans;
}

// optimal
// TC : O(n1 + n2)
// SC : O(n1 + n2)
vector<int> sortedArray1(vector<int> a, vector<int> b) {
    int i = 0, j = 0, n1 = a.size(), n2 = b.size();
    vector<int> ans;
    while(i < n1 && j < n2) {
        if(a[i] <= b[j]) {
            if(ans.size() == 0 || ans.back() != a[i])
                ans.push_back(a[i]);
            i++;
        }
        else {
            if(ans.size() == 0 || ans.back() != b[j])
                ans.push_back(b[j]);
            j++;
        }
    }
    while(i < n1) {
        if(ans.size() == 0 || ans.back() != a[i])
            ans.push_back(a[i]);
        i++;
    }
    while(j < n2) {
        if(ans.size() == 0 || ans.back() != b[j])
            ans.push_back(b[j]);
        j++;
    }
    return ans;
}