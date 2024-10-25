class DisjointSet{
public:
    vector<int> rank, parent;
    DisjointSet(int n) {
        rank.resize(n+1,0);
        parent.resize(n+1,0);
        //initially the parents are themselves
        for(int i = 0;i <= n;i++) {
            parent[i] = i;
        }
    }

    //to find the ultimate parent of a given node
    int findUPar(int node) {
        if(node == parent[node]) return node;
        //path compression
        return parent[node] = findUPar(parent[node]);
    }

    //to merge the both components based on rank
    void unionByRank(int u, int v) {
        //get the ultimate parents of both nodes
        //path compression is done on the way
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        //both nodes belong to same component
        if(ulp_u == ulp_v) return;
        //if rank is not same for ultimate parents
        if(rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        }
        else if(rank[ulp_u] > rank[ulp_v]) {
            parent[ulp_v] = ulp_u;
        }
        //if rank is same then merge anyone of our choice
        //then update the rank in this case.
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