class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        for(int i =0; i<n; i++){
            if(nums[i] == val){
                
                nums.erase(remove(nums.begin(), nums.end(), val), nums.end());
            }

        }
        int k = nums.size();
        return k ;
    }
};