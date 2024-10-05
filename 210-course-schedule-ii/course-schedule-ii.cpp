class Solution {
public:
    bool isCycle(int node, vector<vector<int>> &adj, vector<bool> &visited, vector<bool> &path_visited, stack<int> &sta) {
        visited[node] = true;
        path_visited[node] = true;
        for(auto &child : adj[node]) {
            if(!visited[child]) {
                if(isCycle(child, adj, visited, path_visited, sta)) {
                    return true;
                }
            }
            else if(path_visited[child]) return true;
        }
        path_visited[node] = false;
        sta.push(node);
        return false;
    }
    vector<int> findOrder(int V, vector<vector<int>>& pre) {
        vector<vector<int>> adj(V, vector<int> ());
        for(auto &x : pre) {
            adj[x[1]].push_back(x[0]);
        }
        stack<int> sta;
        vector<bool> visited(V,false);
        vector<bool> path_visited(V,false);
        for(int i = 0;i < V;i++) {
            if(!visited[i]) {
                if(isCycle(i, adj, visited, path_visited, sta)) {
                    return {};
                }
            }
        }
        vector<int> order;
        while(!sta.empty()) {
            order.push_back(sta.top());
            sta.pop();
        }
        return order;
    }
};