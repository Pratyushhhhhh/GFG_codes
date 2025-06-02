// User function Template for C++
class Solution {
    private:
    void dfs(int start,vector<int>&vis,vector<pair<int,int>>adj[],stack<int>&st)
    {
        vis[start]=1;
        for(auto it:adj[start]){
            if(!vis[it.first])
                dfs(it.first,vis,adj,st);
        }
        st.push(start);
    }
    
  public:
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        // code here
        vector<pair<int,int>>adj[V];
        for(auto it:edges)
        {
            int u=it[0];
            int v=it[1];
            int w=it[2];
            adj[u].push_back({v,w});
        }
        vector<int>vis(V,0);
        vector<int>dist(V,INT_MAX);
        int src=0;
        dist[src]=0;
        stack<int>st;
        for(int i=0;i<V;i++)
        {
            if(!vis[i])
            dfs(i,vis,adj,st);
        }
        
        while(!st.empty())
        {
            int node = st.top();
            st.pop();
            if (dist[node] != INT_MAX) 
            {
                for(auto it:adj[node])
                {
                    int du = dist[node];
                    int next=it.first;
                    int dv=it.second;
                    
                    if(du+dv<dist[next])
                        dist[next]=du+dv;
                    
                }
            }
            else
                dist[node]=-1;
        }
        return dist;
        
    }
};
