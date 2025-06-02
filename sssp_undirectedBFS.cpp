class Solution {
  public:
    
   vector<int> shortestPath(vector<vector<int>>& adj, int src) {
        int v = adj.size();
        vector<int> dist(v, INT_MAX);
        queue<int> q;

        dist[src] = 0;
        q.push(src);

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (auto it : adj[node]) {
                if (dist[node] + 1 < dist[it]) {
                    dist[it] = dist[node] + 1;
                    q.push(it);
                }
            }
        }

        for (int i = 0; i < v; i++) {
            if (dist[i] == INT_MAX) dist[i] = -1;
        }

        return dist;
    }
};