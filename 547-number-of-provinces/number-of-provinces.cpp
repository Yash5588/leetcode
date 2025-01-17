class DisjointSet{
public:
    vector<int> size, parent;
    DisjointSet(int n) {
        //initial size is 1
        size.resize(n+1,1);
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
    void unionBySize(int u, int v) {
        //get the ultimate parents of both nodes
        //path compression is done on the way
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        //both nodes belong to same component
        if(ulp_u == ulp_v) return;
        //smaller size component merges with larger size component
        if(size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
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
                    ds.unionBySize(i,j);
                }
            }
        }
        int cnt = 0;
        unordered_set<int> comps;
        for(int i = 0;i < n;i++) {
            comps.insert(ds.findUPar(i));
        }
        return comps.size();
    }
};