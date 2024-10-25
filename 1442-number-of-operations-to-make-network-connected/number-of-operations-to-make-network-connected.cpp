class DisjointSet{
public:
    vector<int> rank, parent;
    int extra_edges;
    DisjointSet(int n) {
        rank.resize(n,0);
        parent.resize(n);
        extra_edges = 0;
        for(int i = 0;i < n;i++) {
            //0-based indexing
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
        if(ulp_u == ulp_v) {
            extra_edges++;
            return;
        }
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
    int makeConnected(int n, vector<vector<int>>& connections) {
        DisjointSet ds(n);
        for(auto &x : connections) {
            ds.unionByRank(x[0],x[1]);
        }
        vector<int> parent = ds.parent;
        int components = 0;
        // cout << ds.extra_edges << endl;
        for(int i = 0;i < n;i++) {
            if(parent[i] == i) components++;
        }
        if(ds.extra_edges >= components-1) return components-1;
        return -1;
    }
};