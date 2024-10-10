class Solution {
public:
    bool dfs(int node, vector<bool> &visited, vector<bool> &path_visited, vector<vector<int>> &adj) {
        visited[node] = true;
        path_visited[node] = true;
        for(auto &child : adj[node]) {
            if(!visited[child]) {
                if(dfs(child, visited, path_visited,adj)) {
                    return true;
                }
            }
            else if(path_visited[child]) {
                return true;
            }
        }
        path_visited[node] = false;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<bool> visited(V,false);
        vector<bool> path_visited(V,false);
        for(int i = 0;i < V;i++) {
            if(!visited[i]) {
                dfs(i, visited, path_visited, graph);
            }
        }
        vector<int> res;
        for(int i = 0;i < V;i++) {
            if(!path_visited[i]) {
                res.push_back(i);
            }
        }
        return res;
    }
};