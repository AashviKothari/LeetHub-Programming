class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& g) {
        int n=g.size();
        vector<int> adj[n];
        vector<int> deg(n,0);
        for(int i=0;i<n;i++)
        {
            for(int it:g[i])
            {
                adj[it].push_back(i);
                deg[i]++;
            }
        }
        queue<int> q;
        for(int i=0;i<n;i++)
        {
            if(deg[i]==0)
            {
                q.push(i);
            }
        }
        vector<int> ans;
        while(!q.empty())
        {
            int node=q.front();
            ans.push_back(node);
            q.pop();
            for(auto i:adj[node])
            {
                deg[i]--;
                if(deg[i]==0)
                {
                    q.push(i);
                }
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};