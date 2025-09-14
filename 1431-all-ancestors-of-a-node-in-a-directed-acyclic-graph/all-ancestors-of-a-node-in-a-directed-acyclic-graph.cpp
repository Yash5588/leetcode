class Solution {
public:
    unordered_map<int,vector<int>> adj;
    set<int> dfs(int node, vector<bool> &visited, vector<set<int>> &res) {
        if(visited[node]) return res[node];
        visited[node] = true;

        set<int> ancestors;

        for(auto &parent : adj[node]) {
            set<int> parentAncestors;
            ancestors.insert(parent);
            parentAncestors = dfs(parent,visited, res);
            ancestors.insert(parentAncestors.begin(),parentAncestors.end());
        }
        return res[node] = ancestors;
    }
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        //reverse edges
        for(auto &edge : edges) {
            adj[edge[1]].push_back(edge[0]);
        }
        vector<bool> visited(n,false);
        vector<set<int>> res(n);
        for(int i = 0;i < n;i++) {
            if(!visited[i]) {
                dfs(i,visited,res);
            }
        }
        vector<vector<int>> ans(n);
        for(int i = 0;i < n;i++) {
            ans[i] = vector<int> (res[i].begin(),res[i].end());
        }
        return ans;
    }
};