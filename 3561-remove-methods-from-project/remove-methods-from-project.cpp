class Solution {
public:
    void dfs(int node, vector<int> &doubt, vector<vector<int>> &adj) {
        if(doubt[node]) return;
        doubt[node] = true;
        for(auto &x : adj[node]) {
            if(!doubt[x]) {
                dfs(x, doubt, adj);
            }
        }
    }
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        int V = n;
        n = invocations.size();
        vector<vector<int>> adj(V, vector<int>());
        vector<int> doubt(V,false);
        for(auto &x : invocations) {
            adj[x[0]].push_back(x[1]);
        }
        dfs(k, doubt, adj);
        bool flag = false;
        for(int i = 0;i < V;i++) {
            if(!doubt[i]) {
                for(auto &x : adj[i]) {
                    if(doubt[x]) {
                        flag = true;
                        break;
                    }
                }
                if(flag) break;
            }
        }
        vector<int> res;
        if(flag) {
            for(int i = 0;i < V;i++) {
                res.push_back(i);
            }
        }
        else {
            for(int i = 0;i < V;i++) {
                if(!doubt[i]) res.push_back(i);
            }
        }
        return res;
    }
};