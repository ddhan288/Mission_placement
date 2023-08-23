class Solution {
public:
    string reorganizeString(string s) {
        vector<int> a(26,0);
        for(auto i:s)
        {
            a[i-'a']++;
        }

        priority_queue<vector<int>> pq;
        for(int i=0;i<26;i++)
        {
            if(a[i])pq.push({a[i],i});
        }

        string ans="";

        while(pq.size()>1)
        {
            int x=pq.top()[0];
            char add1=pq.top()[1]+'a';
            pq.pop();
            int y=pq.top()[0];
            char add2=pq.top()[1]+'a';
            pq.pop();

            string temp="";
            temp+=add1;
            temp+=add2;

            ans+=temp;
            if(x>1)
            {
                pq.push({x-1,add1-'a'});
            }

            if(y>1)
            {
                pq.push({y-1,add2-'a'});
            }
        }

        if(pq.size()==1)
        {
            if(pq.top()[0]>1)return "";

            char x=pq.top()[1]+'a';
            if(ans.size()!=0 && x==ans.back())return "";
            ans+=x;
        }

        return ans;
    }
};