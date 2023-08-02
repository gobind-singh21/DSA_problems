#include <bits/stdc++.h>

using namespace std;

// TC : E log V
// E : number of edges
// V : number of nodes

class Solution {
public:
    vector<int> dijkstra(int V, vector<vector<int>> adj[], int S) {
        set<pair<int, int>> st;
        vector<int> ans(V, INT_MAX);
        st.insert({0, S});
        ans[S] = 0;
        while(!st.empty()) {
            pair<int, int> it = *(st.begin());
            int node = it.second, d = it.first;
            st.erase(it);
            for(auto &itr : adj[node]) {
                int adjNode = itr[0], dist = itr[1];
                int distance = d + dist;
                if(distance < ans[adjNode]) {
                    if(ans[adjNode] != INT_MAX)
                        st.erase({ans[adjNode], adjNode});
                    ans[adjNode] = distance;
                    st.insert({distance, adjNode});
                }
            }
        }
        return ans;
    }
};

int main() {
    return 0;
}