class DisjointSet{
public:
    vector<int> rank, parent;
    DisjointSet(int n) {
        rank.resize(n+1,0);
        parent.resize(n+1,0);
        for(int i = 0;i <= n;i++) {
            parent[i] = i;
        }
    }

    int findUPar(int node) {
        if(node == parent[node]) return node;
        //path compression
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        //both nodes belong to same component
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
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        DisjointSet ds(n);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < n;j++) {
                if(isConnected[i][j] == 1) {
                    ds.unionByRank(i,j);
                }
            }
        }
        vector<int> parent = ds.parent;
        int cnt = 0;
        for(int i = 0;i < n;i++) {
            if(i == parent[i]) cnt++;
        }
        return cnt;
    }
};