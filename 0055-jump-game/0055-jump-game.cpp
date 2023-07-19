// class Solution {
// public:
//     bool canJump(vector<int>& nums) {
        
//         int maxReachable = nums[0];
//         int i =1;
        
//         while ( i < nums.size() && maxReachable >= i  ){
//             if (i + nums[i] > maxReachable ){
//                 maxReachable = i + nums[i];
//             }
//             i++;
            
//         }
//         if (maxReachable >= nums.size()-1){
//             return true;
//         }
//         else 
//             return false;
            
//         }
    
// };


class Solution {
public:
    bool canJump(vector<int>& nums) {
    int n = nums.size();
    int maxReach = 0;
    for (int i = 0; i < n; i++) {
        if (i > maxReach) return false;
        maxReach = max(maxReach, i + nums[i]);
    }
    return true;
}
};


