class Solution {
public:
    void dfs(int node, vector<vector<int>> &adj, vector<bool> &visited) {
        visited[node] = true;
        for(int i = 0;i < adj[node].size();i++) {
            if(adj[node][i] == 1) {
                if(!visited[i]) {
                    dfs(i, adj, visited);
                }
            }
        }
    }
    int findCircleNum(vector<vector<int>>& connect) {
        int V = connect.size();
        vector<bool> visited(V,false);
        int ans = 0;
        for(int i = 0;i < V;i++) {
            if(!visited[i]) {
                ans++;
                cout << i << endl;
                dfs(i, connect, visited);
            }
        }
        return ans;
    }
};