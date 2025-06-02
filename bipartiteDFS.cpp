class Solution {
    private:
    bool dfs(int start,int c,vector<int>&color,vector<int>adj[])
    {
        color[start]=c;
        for(auto it:adj[start])
        {
            if(color[it]==-1)
            {
                if(dfs(it,!c,color,adj)==false) return false;
            }
            else if(color[it]==c)//color of adj is equal to color of prev
            return false;
        }
        return true;
    }
  public:
    bool isBipartite(int V, vector<vector<int>> &edges) {
        // Code here
        vector<int>color(V,-1);
        vector<int>adj[V];
        for(auto it: edges)
        {
            int u=it[0];
            int v=it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        for(int i=0;i<V;i++)
        {
            if(color[i]==-1)
            {
                if(dfs(i,0,color,adj)==false) return false;
            }
        }
        return true;
    }
};