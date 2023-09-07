#include <bits/stdc++.h>

using namespace std;

void printV(vector<string> arr) {
    for(string &str : arr)
        cout << str << ' ';
    cout << endl;
}

void printS(set<string> st) {
    for(auto &str : st)
        cout << str << ' ';
    cout << endl;
}

class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        set<string> st(wordList.begin(), wordList.end());
        queue<vector<string>> q;
        q.push({beginWord});
        vector<string> usedOnLevel;
        usedOnLevel.push_back(beginWord);
        int level = 0;
        vector<vector<string>> ans;
        while(!q.empty()) {
            vector<string> vec = q.front();
            // printV(vec);
            q.pop();
            if(vec.size() > level) {
                level++;
                for(string &it : usedOnLevel)
                    st.erase(it);
                printS(st);
                // usedOnLevel.clear();
            }
            string word = vec.back();
            if(word == endWord) {
                if(ans.size() == 0)
                    ans.push_back(vec);
                else if(ans[0].size() == vec.size())
                    ans.push_back(vec);
            }
            int m = word.size();
            for(int i = 0; i < m; i++) {
                char original = word[i];
                for(char ch = 'a'; ch <= 'z'; ch++) {
                    word[i] = ch;
                    if(st.find(word) != st.end()) {
                        usedOnLevel.push_back(word);
                        vec.push_back(word);
                        q.push(vec);
                        vec.pop_back();
                    }
                }
                word[i] = original;
            }
        }
        return ans;
    }
};

void print(vector<vector<string>> arr) {
    for(vector<string> &a : arr) {
        for(string &str : a)
            cout << str << ' ';
        cout << endl;
    }
}

int main() {
    Solution obj;
    vector<string> wordList = {"des", "der", "dfr", "dgt", "dfs"};
    print(obj.findLadders("der", "dfs", wordList));
    return 0;
}