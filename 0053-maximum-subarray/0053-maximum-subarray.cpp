
// kadane's Algorithm approach
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int currentMaxSum = nums[0], currentSum =nums[0];
        for (int i = 1; i<n; i++){
           if (currentSum < 0){
               currentSum = 0;
           }
            currentSum = currentSum + nums[i];
            if (currentSum >= currentMaxSum){
                currentMaxSum = currentSum;
            }
        }
        return currentMaxSum;
    }
};