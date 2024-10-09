class Solution {
public:
    unordered_map<int,vector<int>> adj;
    bool dfs(int node, int parent, vector<bool> &visited) {
        visited[node] = true;
        for(auto &child : adj[node]) {
            if(!visited[child]) {
                if(dfs(child,node,visited)) return true;
            }
            else {
                if(parent != child) return true;
            }
        }
        return false;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        for(auto &x : edges) {
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
            vector<bool> visited(n+1,false);
            if(dfs(x[0],-1,visited)) return x;
        }
        return  {};
    }
};