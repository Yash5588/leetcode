class Solution {
public:
    unordered_map<int, vector<int>> adj;
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V = graph.size();
        for(int i = 0;i < V;i++) {
            for(auto &x : graph[i]) {
                adj[x].push_back(i);
            }
        }
        vector<int> indegree(V,0);
        for(int i = 0;i < V;i++) {
            for(auto &x : adj[i]) {
                indegree[x]++;
            }
        }
        queue<int> que;
        for(int i = 0;i < V;i++) {
            if(indegree[i] == 0) que.push(i);
        }
        vector<int> res;
        while(!que.empty()) {
            int node = que.front();
            que.pop();
            res.push_back(node);
            for(auto &x : adj[node]) {
                indegree[x]--;
                if(indegree[x] == 0) {
                    que.push(x);
                }
            }
        }
        sort(res.begin(),res.end());
        return res;
    }
};