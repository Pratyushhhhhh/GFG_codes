class Solution {
    private:
    bool dfs(int start,vector<int>&vis,vector<int>&pathVis,vector<int>adj[])
    {
        vis[start]=1;
        pathVis[start]=1;
        for(auto it:adj[start])
        {
            if(!vis[it])
            {
                if(dfs(it,vis,pathVis,adj)==true)
                return true;
            }//if visited and same path then its a cycle
            else if(pathVis[it])
            return true;
        }
        
        pathVis[start]=0;
        return false;
    }
  public:
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
        vector<int>vis(V,0);
        vector<int>pathVis(V,0);
        vector<int>adj[V];
        for(auto it: edges)
        {
            int u=it[0];
            int v=it[1];
            adj[u].push_back(v);
        }
         
        for(int i=0;i<V;i++)
        {
            if(!vis[i])
            {
                if(dfs(i,vis,pathVis,adj)==true)
                return true;
            }
        }
        return false;
        
    }
};