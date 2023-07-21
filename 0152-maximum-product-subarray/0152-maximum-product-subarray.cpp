class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans = 0 ;
        if (nums.size() ==  1){
            return nums[0];
        }
        int currentPdt =1;
        for (int i=0 ; i< nums.size()-1; i++){
            if (nums[i] !=0){
                currentPdt = currentPdt * nums[i];
                if ( currentPdt > ans){
                    ans = currentPdt;
                }
            }
            else {
                currentPdt =1;
            }
            
        }
         currentPdt =1;
        for ( int i=nums.size()-1; i>=0; i--){
            if (nums[i] !=0){
                currentPdt = currentPdt * nums[i];
                if ( currentPdt > ans){
                    ans = currentPdt;
                }
            }
            else {
                currentPdt =1;
            }
            
        }
        return ans;
        
        
        
    }
};