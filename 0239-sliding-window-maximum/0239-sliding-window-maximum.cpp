class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<array<int,2>> st;
        int n=nums.size();

        for(int i=0;i<k-1;i++)
        {
            while(!st.empty() && st.back()[1]<=nums[i])
            {
                st.pop_back();
            }
            st.push_back({i,nums[i]});
        }
        vector<int> ans;

        for(int i=k-1;i<n;i++)
        {
            while(!st.empty() && st.back()[1]<=nums[i])
            {
                st.pop_back();
            }
            st.push_back({i,nums[i]});

            if(st.front()[0]<=i-k)
            {
                st.pop_front();
            }
            ans.push_back(st.front()[1]);
        }
        return ans;
    }
};