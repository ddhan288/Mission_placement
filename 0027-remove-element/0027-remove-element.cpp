class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int size = 0;
        for(int i =0; i< nums.size(); i++){
            if(nums[i] != val){
                nums[size] = nums[i];
                size++;
            }
        }
        return size;
    }
};






//Brute Force O(n^2) 
// class Solution {
// public:
//     int removeElement(vector<int>& nums, int val) {
//         int n = nums.size();
//         sort(nums.begin(),nums.end());
//         for(int i =0; i<n; i++){
//             if(nums[i] == val){
                
//                 // nums.erase(remove(nums.begin(), nums.end(), val), nums.end());
//                 auto iterator= remove(nums.begin(),nums.end(),val);
//                 nums.erase(iterator,nums.end());
//             }

//         }
//         int k = nums.size();
//         return k ;
//     }
// };