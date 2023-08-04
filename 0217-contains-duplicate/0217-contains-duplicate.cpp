// using hashmap optimised version 
// time complexity O(n)
// space complexity O(n)
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        map<int, int >M;
        for(auto i: nums){
            M[i]++;
        }
        for ( auto i: M){
            if ( i.second>1)
                return 1;
        }
        return 0;
    }
    
};

// //sorting
// // Time complexity: O(nlogn)
// // Space complexity: O(1)
// class Solution {
// public:
//     bool containsDuplicate(vector<int>& nums) {
//         sort(nums.begin(), nums.end());
//         for (int i=0;i<nums.size()-1; i++){
//             if (nums[i] == nums[i+1])
//                 return 1;
            
//         }
//         return false;
        
//     }
    
// };


