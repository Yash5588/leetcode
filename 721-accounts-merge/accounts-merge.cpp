class disjointSet{
public:
    vector<int> parent,rank;
    disjointSet(int n) {
        parent.resize(n);
        rank.resize(n,0);
        for(int i = 0;i < n;i++) {
            parent[i] = i;
        }
    }

    int findUPar(int node) {
        if(node == parent[node]) return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if(ulp_u == ulp_v) return;
        if(rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        }
        else if(rank[ulp_u] > rank[ulp_v]) {
            parent[ulp_v] = ulp_u;
        }
        else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
};
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        vector<vector<string>> ans(n,vector<string>());
        for(int i = 0;i < n;i++) {
            ans[i].push_back(accounts[i][0]);
        }
        disjointSet ds(n);
        unordered_map<string,int> mp;
        for(int i = 0;i < accounts.size();i++) {
            for(int j = 1;j < accounts[i].size();j++) {
                if(mp.find(accounts[i][j]) == mp.end()) {
                    mp[accounts[i][j]] = i;
                }
                else {
                    ds.unionByRank(i,mp[accounts[i][j]]);
                }
            }
        }
        // for(auto &x : parent) cout << x << endl;
        for(auto &[key,value] : mp) {
            // cout << key << ' ' << value << endl;
            int par = ds.findUPar(value);
            ans[par].push_back(key);
        }
        vector<vector<string>> res;
        for(auto &x : ans) {
            if(x.size() > 1) {
                sort(x.begin()+1,x.end());
                res.push_back(x);
            } 
        }
        return res;
    }
};