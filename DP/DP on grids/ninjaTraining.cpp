#include <bits/stdc++.h>

using namespace std;

int calculatePoints(vector<vector<int>> &points, int day, int lastTask, vector<vector<int>> &dp) {
    if(day == 0) {
        int maxi = 0;
        for(int i = 0; i < 3; i++) {
            if(i != lastTask)
                maxi = max(maxi, points[day][i]);
        }
        return maxi;
    }

    if(dp[day][lastTask] != -1)
        return dp[day][lastTask];
    int maxi = 0;
    for(int i = 0; i < 3; i++) {
        if(i != lastTask) {
            int score = points[day][i] + calculatePoints(points, day - 1, i, dp);
            maxi = max(score, maxi);
        }
    }
    return dp[day][lastTask] = maxi;
}

int ninjaTraining(int n, vector<vector<int>> &points) {

}

int main() {
    return 0;
}