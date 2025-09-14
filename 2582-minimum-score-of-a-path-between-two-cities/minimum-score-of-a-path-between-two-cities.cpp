class Solution {
public:
    int mxm = INT_MAX;
    unordered_map<int,vector<pair<int,int>>> adj;
    void dfs(int node, vector<bool> &visited) {
        for(auto &child : adj[node]) {
            mxm = min(mxm, child.second);
            if(!visited[child.first]) {
                visited[child.first] = true;
                dfs(child.first, visited);
            }
        }
    }
    int minScore(int n, vector<vector<int>>& roads) {
        for(auto &edge : roads) {
            adj[edge[0]].push_back({edge[1],edge[2]});
            adj[edge[1]].push_back({edge[0],edge[2]});
        }
        vector<bool> visited(n+1,false);
        visited[1] = true;
        dfs(1,visited);
        return mxm;
    }
};