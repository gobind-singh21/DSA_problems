#include <iostream>
#include <vector>

using namespace std;

int calculate(int index, int target, vector<int> &arr, vector<vector<int>> &dp) {
    if(index == 0){
        if(target==0 && arr[0]==0)
            return 2;
        if(target==0 || target == arr[0])
            return 1;
        return 0;
    }
    if(dp[index][target]!=-1)
        return dp[index][target];
        
    int notTaken = calculate(index-1,target,arr,dp);
    
    int taken = 0;
    if(arr[index]<=target)
        taken = calculate(index-1,target-arr[index],arr,dp);
        
    return dp[index][target]= (notTaken + taken);
}

int targetSum(int n, int target, vector<int> &arr) {
    int totSum = 0;
    for(int i=0; i<arr.size();i++){
        totSum += arr[i];
    }
    if(totSum-target<0) return 0;
    if((totSum-target)%2==1) return 0;
    
    int s2 = (totSum-target)/2;
    
    vector<vector<int>> dp(n,vector<int>(s2+1,-1));
    return calculate(n-1,s2,arr,dp);
}

int main() {
    return 0;
}