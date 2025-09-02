class Solution {
public:
    unordered_map<int,vector<int>> adj;
    void dfs(vector<int> &assign, int node) {
        for(auto &child : adj[node]) {
            if(assign[child] == -1) {
                vector<bool> used(5,false);
                used[assign[node]] = true;
                for(auto &neighbour : adj[child]) {
                    if(assign[neighbour] != -1) {
                        used[assign[neighbour]] = true;
                    }
                }
                for(int color = 1;color <= 4;color++) {
                    if(!used[color]) {
                        assign[child] = color;
                        break;
                    }
                }
                dfs(assign, child);
            }
        }
    }
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        vector<int> assign(n+1,-1);
        for(auto &x : paths) {
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        for(int i = 1;i <= n;i++) {
            if(assign[i] == -1) {
                assign[i] = 1;
                dfs(assign, i);
            }
        }
        vector<int> result(assign.begin()+1, assign.end());
        return result;
    }
};