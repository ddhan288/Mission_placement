class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> dp(n+1); // Initialize dp vector with size n+1

        int offset = 1;
        for (int i = 1; i <= n; i++) { // Change condition to <= and start from 1
            if (offset * 2 == i) {
                offset = i;
            }
            dp[i] = 1 + dp[i - offset]; // Change '+' to '-' for correct index calculation
        }
        
        return dp;
    }
};

