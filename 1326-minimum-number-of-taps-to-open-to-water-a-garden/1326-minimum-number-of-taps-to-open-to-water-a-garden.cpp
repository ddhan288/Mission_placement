class Solution {
public:
    static bool comp(const vector<int>&a,const vector<int>&b)
    {
        if(a[0]==b[0])return a[1]>b[1];

        return a[0]<b[0];
    }
    int minTaps(int n, vector<int>& ranges) {
        
        vector<vector<int>> v;

        for(int i=0;i<=n;i++)
        {
            int left=max(0,i-ranges[i]);
            int right=min(n,i+ranges[i]);
            v.push_back({left,right});
            
        }

        sort(v.begin(),v.end(),comp);

        stack<vector<int>> st;
        st.push(v[0]);


        for(int i=1;i<=n;i++)
        {
            if(st.top()[1]<v[i][1])
            {
                if(st.top()[1]<v[i][0])return -1;

                while(!st.empty() && st.top()[0]>=v[i][0] && st.top()[1]<=v[i][1])
                {
                    st.pop();
                }

                st.push({max(st.top()[1],v[i][0]),v[i][1]});
            }
        }

       
        return st.size();

    }
};