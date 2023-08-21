class Solution {
public:

    vector<int> solve(vector<int>&v,vector<vector<int>>&edges)
    {
        map<int,int> m;

        for(auto i:v)
        {
            m[i]=0;
        }

        vector<int> temp;
        map<int,vector<int>> adj;
        for(auto a:edges)
        {
            adj[a[0]].push_back(a[1]);
            m[a[1]]++;
        }

        queue<int> q;

        for(auto i:m)
        {
            if(i.second==0)q.push(i.first);
        }

        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            temp.push_back(node);

            for(auto nbr:adj[node])
            {
                m[nbr]--;
                if(m[nbr]==0)q.push(nbr);
            }
        }

        return temp;
    }
    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
       
       for(int i=0;i<n;i++)
       {
           if(group[i]==-1)
           {
               group[i]=m;
               m++;
           }
       }

       vector<vector<int>> adj(m);
       vector<vector<int>> groups(m);

       vector<vector<int>> group_edges[m];

       for(int i=0;i<n;i++)
       {
           groups[group[i]].push_back(i);
       }
       vector<int> incoming(m,0);
       for(int i=0;i<n;i++)
       {

           vector<int> v=beforeItems[i];
           int g1=group[i];
           for(auto j:v)
           {
                int g2=group[j];

                

                if(g1==g2)
                {
                    group_edges[g1].push_back({j,i});
                }
                else{
                    adj[g2].push_back(g1);
                    incoming[g1]++;
                }
           }
       }

       queue<int> q;
       for(int i=0;i<m;i++)
       {
           if(incoming[i]==0)q.push(i);
       }

       vector<int> temp;
       while(!q.empty())
       {
           int node=q.front();
           temp.push_back(node);
           q.pop();

           for(auto nbr:adj[node])
           {
               incoming[nbr]--;
               if(incoming[nbr]==0)
               {
                   q.push(nbr);
               }
           }
       }

       if(temp.size()!=m)return {};

       
       
       vector<int> ans;
       for(auto i:temp)
       {
           vector<int> curr=solve(groups[i],group_edges[i]);

           if(curr.size()!=groups[i].size())return {};
           

           for(auto j:curr)
           {
               ans.push_back(j);
           }
       }

       return ans;
    }
};