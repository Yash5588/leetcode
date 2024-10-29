class DisjointSet{
public:
    vector<int> parent, size;
    DisjointSet(int n) {
        parent.resize(n,0);
        size.resize(n,1);
        for(int i = 0;i < n;i++) parent[i] = i;
    }

    int findUPar(int node) {
        if(parent[node] == node) return node;
        return parent[node] = findUPar(parent[node]);
    } 

    void unionBySize(int u, int v) {
        int ult_u = findUPar(u);
        int ult_v = findUPar(v);
        if(ult_u == ult_v) return;
        if(size[ult_u] <= size[ult_v]) {
            parent[ult_u] = ult_v;
            size[ult_v] += size[ult_u];
        }
        else {
            parent[ult_v] = ult_u;
            size[ult_u] += size[ult_v];
        }
    }
};

class Solution {
public:
    vector<pair<int,int>> adj = {{-1,0},{0,-1},{0,1},{1,0}};
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        DisjointSet ds(m*n);
        for(int i = 0;i < m;i++) {
            for(int j = 0;j < n;j++) {
                if(grid[i][j] == 0) continue;
                for(int k = 0;k < 4;k++) {
                    int nr = i + adj[k].first;
                    int nc = j + adj[k].second;
                    if(nr >= 0 && nr < m && nc >= 0 && nc < n) {
                        if(grid[nr][nc] == 1) {
                        // cout << i << " "<< j << " "<< nr << ' ' << nc <<"\n";

                            int node = i * n + j;
                            int adjNode = nr * n + nc;
                            ds.unionBySize(node, adjNode);
                        }
                    }
                }
            }
        }
        // for(int i = 0;i < m*n;i++) cout << i << ' ' << ds.size[i] << endl;
        int ma = 0; 
        for(int i = 0;i < m;i++) {
            for(int j = 0;j < n;j++) {
                if(grid[i][j] == 1) {
                    int node = i * n + j;
                    ma = max(ma,ds.size[ds.findUPar(node)]);
                }
            }
        }
        return ma;
    }
};