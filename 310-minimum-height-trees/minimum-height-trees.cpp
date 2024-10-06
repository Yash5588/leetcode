class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n == 1) return {0};
        int V = n;
        vector<vector<int>> adj(V, vector<int>());
        for(auto &x : edges) {
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        vector<int> degree(V,0);
        for(int i = 0;i < V;i++) {
            for(auto &x : adj[i]) {
                degree[x]++;
            }
        }
        queue<int> que;
        for(int i = 0;i < V;i++) {
            if(degree[i] == 1) que.push(i);
        }
        vector<bool> visited(V,false);
        vector<int> res;
        while(!que.empty()) {
            res.clear();
            int n = que.size();
            while(n--) {
                int curr = que.front();
                res.push_back(curr);
                que.pop();
                for(auto &x : adj[curr]) {
                    degree[x]--;
                    if(degree[x] == 1) que.push(x);
                }
            }
        }
        return res;
    }
};