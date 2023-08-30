class Solution {
public:
    int dp[510];
    // time Complexity = O(n*n*n*k) - Verdict - TLE
    // int solve(int i, int j,  vector<int> &arr, int t){
    //     if(i > j) return 0;
    //     if(dp[i][j] != -1) return dp[i][j];
    //     if(i == j) return arr[i];
    //     if(j - i + 1 <= t){
    //         int mx = INT_MIN;
    //         for(int x = i; x<=j; x++)mx = max(mx, arr[x]);
    //         return (j-i+1)*mx;
    //     }
    //     int ans = 0;
    //     for(int k = i; k<j; k++){
    //         ans = max(ans,  solve(i, k, arr, t) + solve(k+1, j, arr, t));
    //     }
    //     return dp[i][j] = ans;
    // }

    // using Front Row Partition Dp - Time Complexity = O(n*k)
    int solve(int i, int k, vector<int> &arr){
        if(i == arr.size()) return 0;
        if(dp[i] != -1) return dp[i];
        int ans = 0;
        int mx = 0;
        for(int j = i; j < i + k && j < arr.size(); j++){
            mx = max(mx, arr[j]);
            ans = max(ans, mx*(j-i+1) + solve(j+1, k, arr));
        }
        return dp[i] = ans;
    }

    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        memset(dp, -1, sizeof(dp));
        return solve(0, k, arr);
    }
};