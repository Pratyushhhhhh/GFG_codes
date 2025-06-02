class Solution {
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        int indegree[V]={0};
        vector<int>adj[V];
        for(auto it:edges)
        {
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
        }
        
        for(int i=0;i<V;i++)
        {
            for(auto it:adj[i])
                indegree[it]++;
        }
        
        queue<int>q;
        for(int i=0;i<V;i++)
        {
            if(indegree[i]==0)
                q.push(i);
        }
        
        vector<int>topo;
        while(!q.empty())
        {
            int node=q.front();
            topo.push_back(node);
            q.pop();
            for(auto it:adj[node])
            {
                indegree[it]--;
                if(indegree[it]==0)
                q.push(it);
            }
            
        }
        return topo;
    }
};