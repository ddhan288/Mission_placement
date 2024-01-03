class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int n= bank.size();
        int previousDeviceCount =0;
        int result = 0;
        
        for (int i =0; i<n; i++){
            
            int currDeviceCount = 0;
            for (char &ch : bank[i]){
                if (ch == '1'){
                    currDeviceCount++;
                }
                
                }
            result += (currDeviceCount*previousDeviceCount);
            if (currDeviceCount !=0){
                    previousDeviceCount = currDeviceCount;
                
            }
        }
        return result;
    }
};