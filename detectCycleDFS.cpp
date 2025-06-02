class Solution {
    private:
    bool dfs(int node, int parent ,vector<int> adj[],vector<int>&vis)
    {
        vis[node]=1;
        for(auto it: adj[node])
        {
            if(!vis[it])
            {
                if(dfs(it,node,adj,vis)==true)
                return true;
            }
            else if(parent!=it) return true;
        }
        return false;
    }
  public:
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        vector<int> vis(V,0);
        vector<int>adj[V];
        for(auto it:edges)
        {
            int u=it[0];
            int v=it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        for(int i=0;i<V;i++)
        {
            if(!vis[i])
            {
                if(dfs(i,-1,adj,vis)==true) return true;
            }
        }
        return false;
    }
};