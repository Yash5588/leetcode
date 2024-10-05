class Solution {
public:
    bool isCycle(int node, vector<vector<int>> &adj, vector<bool> &visited, vector<bool> &path_visited) {
        visited[node] = true;
        path_visited[node] = true;
        for(auto &child : adj[node]) {
            if(!visited[child]) {
                if(isCycle(child, adj, visited, path_visited)) return true;
            }
            else if(path_visited[child]) {
                return true;
            }
        }
        path_visited[node] = false;
        return false;
    }
    bool canFinish(int V, vector<vector<int>>& pre) {
        //graph conversion
        vector<vector<int>> adj(V, vector<int>());
        for(auto &x : pre) {
            adj[x[1]].push_back(x[0]);
        }
        vector<bool> visited(V,false);
        vector<bool> path_visited(V,false);
        //code to detect cycle in directed graph
        for(int i = 0;i < V;i++) {
            if(!visited[i]) {
                if(isCycle(i, adj, visited, path_visited)) return false;
            }
        }
        return true;
    }
};