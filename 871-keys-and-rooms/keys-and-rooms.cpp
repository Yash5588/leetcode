class Solution {
public:
    void solve(int node, vector<bool> &visited, vector<vector<int>> &adj) {
        visited[node] = true;
        for(auto &child : adj[node]) {
            if(!visited[child]) {
                solve(child, visited, adj);
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool> visited(n,false);
        solve(0,visited,rooms);
        for(auto x : visited) {
            n -= x;
        }
        return n == 0;
    }
};