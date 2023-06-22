#include <iostream>
#include <vector>

using namespace std;

vector<vector<string>> answer(0);

void printAns(vector<vector<string>> arr) {
    for(vector<string> temp : arr) {
        for(string str : temp)
            cout << str << ' ';
        cout << endl;
    }
}

bool isPalindrome(string str, int start, int end) {
    while(start <= end) {
        if(str[start++] != str[end--])
            return false;
    }
    return true;
}

void partition(string str, int index, vector<string> currPartition) {
    int n = str.size();
    if(index == n) {
        answer.push_back(currPartition);
        return;
    }
    for(int i = index; i < n; i++) {
        if(isPalindrome(str, index, i)) {
            currPartition.push_back(str.substr(index, i - index + 1));
            partition(str, i + 1, currPartition);
            currPartition.pop_back();
        }
    }
}

int main() {
    partition("aabb",0,{});
    printAns(answer);
    return 0;
}