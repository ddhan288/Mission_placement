class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        int dp[n][amount+1];
        memset(dp,0,sizeof(dp));
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<=amount;j++)
            {
                if(j==0)
                {
                    dp[i][j]=1;
                    continue;
                }
                
                if(coins[i]<=j)
                {
                    dp[i][j]+=dp[i][j-coins[i]];
                } 
                
                dp[i][j]+= (i==0) ? 0:dp[i-1][j];
            }
        }
        return dp[n-1][amount];
    }
};