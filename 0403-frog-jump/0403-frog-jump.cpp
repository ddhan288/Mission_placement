class Solution {
public:
    bool canCross(vector<int>& stones) {

        if(stones[1]!=1)return false;
        set<int> s;
        for(auto i:stones)
        {
            s.insert(i);
        }

        set<vector<int>> reached;

        queue<vector<int>> q;

        q.push({1,1});

        while(!q.empty())
        {
            int jump=q.front()[0];
            int stone=q.front()[1];

            if(stone==stones.back())return true;

            q.pop();

            if(s.find(stone+(jump-1))!=s.end() && reached.find({stone+jump-1,jump-1})==reached.end())
            {
                reached.insert({{stone+jump-1,jump-1}});
                q.push({jump-1,stone+jump-1});
            }

            if(s.find(stone+(jump))!=s.end() && reached.find({stone+jump,jump})==reached.end())
            {
                reached.insert({{stone+jump,jump}});
                q.push({jump,stone+jump});
            }

            if(s.find(stone+(jump+1))!=s.end() && reached.find({stone+jump+1,jump+1})==reached.end())
            {
                reached.insert({{stone+jump+1,jump+1}});
                q.push({jump+1,stone+jump+1});
            }
        }

        return false;
    }
};