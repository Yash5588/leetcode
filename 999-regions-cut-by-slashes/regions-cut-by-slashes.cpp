class DisjointSet{
public:
    vector<int> parent,size;
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
vector<pair<int,int>> adj = {{-1,0},{0,-1},{0,1},{1,0}};
class Solution {
public:
    int regionsBySlashes(vector<string>& grid) {
        //symbol to matrix conversion
        int n = grid.size();
        vector<vector<int>> new_grid(3*n, vector<int> (3*n,0));
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < n;j++) {
                if(grid[i][j] == '/') {
                    new_grid[i*3][j*3+2] = 1;
                    new_grid[i*3+1][j*3+1] = 1;
                    new_grid[i*3+2][j*3] = 1;
                }
                if(grid[i][j] == '\\') {
                    new_grid[i*3][j*3] = 1;
                    new_grid[i*3+1][j*3+1] = 1;
                    new_grid[i*3+2][j*3+2] = 1;
                }
            }
        }
        int size = 3*n;
        DisjointSet ds(size*size);
        for(int i = 0;i < size;i++) {
            for(int j = 0;j < size;j++) {
                if(new_grid[i][j] == 0) {
                    int node = i * size + j;
                    for(int k = 0;k < 4;k++) {
                        int nr = i + adj[k].first;
                        int nc = j + adj[k].second;
                        if(nr >= 0 && nr < size && nc >= 0 && nc < size && new_grid[nr][nc] == 0) {
                            int adjNode = nr * size + nc;
                            ds.unionBySize(node, adjNode);
                        }
                    }
                }
            }
        }
        int cnt = 0;
        for(int i = 0;i < size;i++) {
            for(int j = 0;j < size;j++) {
                int node = i*size + j;
                if(new_grid[i][j] == 0 && node == ds.findUPar(node)) cnt++;
            }
        }
        return cnt;
    }
};