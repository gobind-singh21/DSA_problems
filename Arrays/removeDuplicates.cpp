#include <bits/stdc++.h>

using namespace std;

// Brute
int removeDuplicates(vector<int> &arr, int n) {
	set<int> st;
    for(int &i : arr)
        st.insert(i);
    int m = st.size();
    for(int i = 0; i < m; i++) {
        arr[i] = *(st.begin());
        st.erase(arr[i]);
    }
    return m;
}

// Optimal
int removeDuplicates2(vector<int> &arr, int n) {
	int i = 0;
	for(int j = 1; j < n; j++) {
		if(arr[i] != arr[j]) {
			i++;
			arr[i] = arr[j];
		}
	}
	return i + 1;
}

int main() {
    return 0;
}