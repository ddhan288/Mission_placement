class Solution {
public:
    bool pos(long long val,long long times,long long n)
    {
        
        long long sum=val*times;
        
        return sum<=n;
    }
    
    long long max_possible(long long n,long long m)
    {
        long long times=(n+(m-1))/m;
        // cout<<"times: "<<times<<"-->";
        
        long long l=1,r=m;
        long long ans=1;
        while(l<=r)
        {
            long long mid=(l+r)/2;
            
            if(pos(mid,times,n))
            {
                ans=mid;
                l=mid+1;
            }
            else{
                r=mid-1;
            }
        }
        
        // cout<<ans<<endl;
        
        return ans;
    }
    long long minimumReplacement(vector<int>& nums) {
        long long curr=1e10;
        int n=nums.size();
        long long ans=0;
        for(int i=n-1;i>=0;i--)
        {
            if(curr>=nums[i])
            {
                curr=nums[i];
                continue;
            }
            
            
            long long temp=((nums[i]+(curr-1))/curr)-1;
            // cout<<"i:"<<i<<endl;
            curr=max_possible(nums[i],curr);
            ans+=temp;
            // cout<<i<<" "<<curr<<"   ans--->"<<ans<<endl;
        }
        
        return ans;
    }
};