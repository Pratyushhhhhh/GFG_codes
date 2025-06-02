// User Function Template
class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // Code here
        vector<pair<int,int>>adj[V];
        for(auto it:edges)
        {
            int u=it[0];
            int v=it[1];
            int w=it[2];
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        vector<int>dist(V,INT_MAX);
        dist[src]=0;
        pq.push({0,src});
        while(!pq.empty())
        {
            int dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            for(auto it:adj[node])
            {
                int edgeWeight =it.second;
                int adjNode = it.first;
                
                if(dis+edgeWeight < dist[adjNode])
                {
                    dist[adjNode]=dis+edgeWeight;
                    pq.push({dist[adjNode],adjNode});
                }
            }
        }
        return dist;
    }
    
};