class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n=obstacleGrid.size();
        int m=obstacleGrid[0].size();
        int dp[n+1][m+1];
        if(obstacleGrid[0][0]==1)
        {
            return 0;
        }
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(obstacleGrid[i-1][j-1]==1)
                {
                    dp[i][j]==0;
                }
                else{
                    dp[i][j]=dp[i-1][j]+dp[i][j-1];
                }
                if(i==1 && j==1)
                {
                    dp[i][j]=1;
                }
            }
        }
        return dp[n][m];
    }
};