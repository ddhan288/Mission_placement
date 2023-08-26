class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        

        sort(pairs.begin(),pairs.end());
        int n=pairs.size();
        vector<int> dp(n,0);
        int ans=0;
        for(int i=0;i<n;i++)
        {

            for(int j=i-1;j>=0;j--)
            {
                if(pairs[i][0]>pairs[j][1])dp[i]=max(dp[j],dp[i]);
            }
            dp[i]+=1;
            ans=max(ans,dp[i]);
        }
        return ans;
    }
};