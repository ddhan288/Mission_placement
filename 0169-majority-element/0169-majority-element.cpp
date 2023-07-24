// solved using moore's voting algorithm
//time complexity O(n)
//space compexity O(1)
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        int count=0;
        int element=0;
        //for(int i=0; i<nums.size(); i++){
        for (int num: nums){
            
            if ( count == 0){
               element = num;
            }
            if(num == element){
                count +=1;
            }
            else 
                count-=1;
            
        }
        return element;
    }
    
};
// this problem can also be solved using Hashmap
//space complexity will increase to O(n)