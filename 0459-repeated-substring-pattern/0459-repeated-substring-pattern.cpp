class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        
        int n=s.size();

        vector<int> pi(n,0);

        for(int i=1;i<n;i++)
        {
            int p=pi[i-1];

            while(p>0 && s[p]!=s[i])
            {
                p=pi[p-1];
            }

            if(s[i]==s[p])
            {
                p++;
            }
            pi[i]=p;
        }

        int p=pi[n-1];
        bool pos=false;
        while(p>0)
        {
            int j=n-1;
            while(j>=p)
            {
                int k=pi[j];
                while(k>p)
                {
                    k=pi[k-1];
                }
                if(k<p)break;
                j-=k;

            }
            if(j==p-1)pos=true;
            p=pi[p-1];
            if(pos)return pos;
        }
        return pos;
    }
};