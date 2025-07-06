class Solution {
private:
    vector<int> topoSort(int K, vector<int> adj[], vector<bool> &used) {
        vector<int> indegree(K, 0);
        for (int i = 0; i < K; i++) {
            for (int neigh : adj[i]) {
                indegree[neigh]++;
            }
        }

        queue<int> q;
        for (int i = 0; i < K; i++) {
            if (used[i] && indegree[i] == 0)
                q.push(i);
        }

        vector<int> topo;
        while (!q.empty()) {
            int node = q.front(); q.pop();
            topo.push_back(node);
            for (int neigh : adj[node]) {
                indegree[neigh]--;
                if (indegree[neigh] == 0)
                    q.push(neigh);
            }
        }

        return topo;
    }

public:
    string findOrder(vector<string> &words) {
        int K = 26; 
        vector<int> adj[K];
        vector<bool> used(K, false);

        for (auto &word : words) {
            for (char c : word)
                used[c - 'a'] = true;
        }
       
        for (int i = 0; i < words.size() - 1; i++) {
            string &s1 = words[i];
            string &s2 = words[i + 1];
            int len = min(s1.size(), s2.size());
            bool found = false;
            for (int j = 0; j < len; j++) {
                if (s1[j] != s2[j]) {
                    adj[s1[j] - 'a'].push_back(s2[j] - 'a');
                    found = true;
                    break;
                }
            }
            if (!found && s1.size() > s2.size())
                return "";
        }

        vector<int> topo = topoSort(K, adj, used);
       
        int usedCount = count(used.begin(), used.end(), true);
        if (topo.size() < usedCount)
            return "";
       
        string result = "";
        for (int ch : topo) {
            if (used[ch])
                result += (char)(ch + 'a');
        }

        return result;
    }
};
