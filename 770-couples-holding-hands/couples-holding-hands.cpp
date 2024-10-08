class Solution {
public:
    int dfs(int node, unordered_map<int, vector<int>> adj, vector<bool> &visited) {
        visited[node] = true;
        int cnt = 0;
        for(auto &child : adj[node]) {
            if(!visited[child]) {
                cnt += 1 + dfs(child, adj, visited);
            }
        }
        return cnt;
    }
    int minSwapsCouples(vector<int>& row) {
        int n = row.size();
        unordered_map<int,vector<int>> adj;
        for(int i = 0;i < n;i += 2) {
            adj[row[i]/2].push_back(row[i+1]/2);
            adj[row[i+1]/2].push_back(row[i]/2);
        }
        vector<bool> visited(n/2,false);
        int ans = 0;
        for(int i = 0;i < n/2;i++) {
            if(!visited[i]) {
                int cnt = dfs(i, adj, visited);
                ans += cnt;
            }
        }
        return ans;
    }
};