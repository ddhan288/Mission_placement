class Solution {
public:
    bool validPartition(vector<int>& nums) {
        int n=nums.size();

        vector<bool> dp(n,false);

        for(int i=0;i<n;i++)
        {
            bool pos=false;
            
            // checking 2
            if(i>=1)
            {
                if(nums[i]==nums[i-1])
                {
                    if(i==1)pos=true;
                    else{
                        pos|=dp[i-2];
                    }
                }
            }

            // checking 3

            if(i>=2)
            {
                if(nums[i]==nums[i-1] && nums[i]==nums[i-2])
                {
                    if(i==2)pos=true;
                    else{
                        pos|=dp[i-3];
                    }
                }
                else if(nums[i]==nums[i-1]+1 && nums[i-1]==nums[i-2]+1)
                {
                    if(i==2)pos=true;
                    else{
                        pos|=dp[i-3];
                    }
                }
            }

            dp[i]=pos;
        }

        return dp[n-1];

    }
};