class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        int i=0,e=n-1;
        
        while(i<=e)
        {
            
            int mid=(i+e)/2;
            // cout<<i<<" "<<e<<" "<<mid<<endl;
            
            if(target==nums[mid])
            {
                return mid;
            }
            
            if(nums[i]<=nums[mid])
            {
                if(target>=nums[i] && target<nums[mid])
                {
                    e=mid-1;
                }
                else{
                    i=mid+1;
                }
            }
            else{
                if(target>nums[mid] && target<=nums[e])
                {
                    i=mid+1;
                }
                else{
                    e=mid-1;
                }
            }
        }
        
        return -1;
        
    }
};