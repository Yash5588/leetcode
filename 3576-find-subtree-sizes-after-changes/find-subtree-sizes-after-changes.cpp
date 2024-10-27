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
        return res[node] = cnt + 1;
    }

    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = parent.size();
        //create an adjacency list
        for(int i = 0;i < n;i++) {
            adj[parent[i]].push_back(i);
        }
        //modify the edges based on question
        changeParents(parent,0,s);
        //clear and again create an adjacency list
        adj.clear();
        for(int i = 0;i < n;i++) {
            adj[parent[i]].push_back(i);
        }
        //store the count of each subtree in their parent index
        res.resize(n,0);
        res[0] = dfs_count(0);
        return res;
    }
};