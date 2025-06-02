class Solution {
    private:
    void dfs(int start,vector<int>&vis,vector<int>adj[],stack<int>&st)
    {
        vis[start]=1;
        for(auto it:adj[start])
        {
            if(!vis[it])
            dfs(it,vis,adj,st);
        }
        st.push(start);
        
    }
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        vector<int>adj[V];
        vector<int>vis(V,0);
        stack<int>st;
        for(auto it:edges)
        {
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
        }
        
        for(int i=0;i<V;i++)
        {
            if(!vis[i])
            {
                dfs(i,vis,adj,st);
            }
        }
        
        vector<int>ans;
        while(!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
        
    }
    
    
};