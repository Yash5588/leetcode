class Solution {
public:
    unordered_map<int,vector<int>> adj;
    unordered_map<char,vector<int>> ances;
    vector<int> res;
    void changeParents(vector<int> &parents, int node, string &s) {
        vector<int> &vec = ances[s[node]];
        if(!vec.empty()) parents[node] = vec.back();
        vec.push_back(node);
        for(auto &child : adj[node]) {
            changeParents(parents,child,s);
        }
        vec.pop_back();
    }

    int dfs_count(int node) {
        int cnt = 0;
        for(auto &child : adj[node]) {
            cnt += dfs_count(child);
        }
        cout << cnt + 1 << endl;
        return res[node] = cnt + 1;
    }

    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = parent.size();
        for(int i = 0;i < n;i++) {
            adj[parent[i]].push_back(i);
        }
        changeParents(parent,0,s);
        adj.clear();
        for(int i = 0;i < n;i++) {
            adj[parent[i]].push_back(i);
        }
        res.resize(n,0);
        res[0] = dfs_count(0);
        return res;
    }
};