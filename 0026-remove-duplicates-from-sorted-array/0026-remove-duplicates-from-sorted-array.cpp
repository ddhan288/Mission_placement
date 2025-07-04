class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty())return 0;
        int left = 1;
        for(int right =1; right < nums.size(); right++){
            if(nums[right] == nums[right -1]){
                continue;
            }
            nums[left] = nums[right];
            left++;
        }
        return left;

    }
};


            

        


//brute foroce solution 
//time Complexity O(n^2)
// class Solution {
// public:
//     int removeDuplicates(vector<int>& nums) {
//         int i = 0; 
//         while (i < nums.size()-1){// O(n)
//             if(nums[i] == nums[i+1]){
//                 nums.erase(nums.begin() + i +1);//O(n)
//             }else{
//                 i++;
//             }
//         }
//         return nums.size();
//     }
// };