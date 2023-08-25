class Solution {
public:
    
    bool solve(string &s,string &t,string &st,int i,int j,int k,vector<vector<int>> &dp)
    {
        
        
        if(k==st.length())
        {
            return dp[i][j]=1;
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        int ans=0;
        if(i<s.length() && st[k]==s[i])
        {
            ans=solve(s,t,st,i+1,j,k+1,dp);
        }
        if(j<t.length() && st[k]==t[j])
        {
            ans+=solve(s,t,st,i,j+1,k+1,dp);
        }
        
        return dp[i][j]= ans>0?1:0;
        
    }
    
    bool isInterleave(string s1, string s2, string s3) {
        int n=s1.length();
        int m=s2.length();
        int x=s3.length();
        
        if(n+m !=x)
        {
            return false;
        }
        
        vector<vector<int>>  dp(n+1,vector<int>(m+1,-1));
        return solve(s1,s2,s3,0,0,0,dp);
    }
};