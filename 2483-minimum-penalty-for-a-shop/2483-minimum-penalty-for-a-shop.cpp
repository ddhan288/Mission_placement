class Solution {
public:
    int bestClosingTime(string customers) {
        int cnty=0;

        for(auto i:customers)
        {
            cnty+=i=='Y';
        }

        int n=customers.size();

        int maxa=n,ans=-1;
        int cntn=0;
        for(int i=0;i<n;i++)
        {
            
            if(cntn+cnty<maxa)
            {
                ans=i;
                maxa=cntn+cnty;
            }

            cnty-=customers[i]=='Y';
            cntn+=customers[i]=='N';
        }

        if(cntn+cnty<maxa)
        {
            ans=n;
        }

        return ans;
    }
};