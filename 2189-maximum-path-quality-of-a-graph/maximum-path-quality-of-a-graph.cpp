class Solution {
public:
    unordered_map<int,vector<pair<int,int>>> adj;
    long long maxVal = INT_MIN;
    void dfs(int node, vector<int> &values, int maxTime, vector<bool> &visited, long long val, int time) {
        if(time > maxTime) return;
        if(node == 0) {
            maxVal = max(maxVal, val);
        }
        for(auto &x : adj[node]) {
            int child = x.first;
            int t = x.second;
            if(!visited[child]) {
                visited[child] = true;
                dfs(child, values, maxTime, visited, val + values[child], time + t);
                visited[child] = false;
            }
            else {
                dfs(child, values, maxTime, visited, val, time + t);
            }
        }
    }

    int maximalPathQuality(vector<int>& values, vector<vector<int>>& edges, int maxTime) {
        int n = values.size();
        for(auto &edge : edges) {
            adj[edge[0]].push_back({edge[1], edge[2]});
            adj[edge[1]].push_back({edge[0], edge[2]});
        }
        vector<bool> visited(n,false);
        visited[0] = true;
        maxVal = values[0];
        dfs(0, values, maxTime, visited, values[0], 0);
        return maxVal;
    }
};