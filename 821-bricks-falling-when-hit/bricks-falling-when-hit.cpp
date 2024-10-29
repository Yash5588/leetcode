class DisjointSet {
public:
    vector<int> parent, size;
    DisjointSet(int n) {
        parent.resize(n);
        size.resize(n, 1);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int findUPar(int node) {
        if (parent[node] == node) return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionBySize(int u, int v) {
        int ult_u = findUPar(u);
        int ult_v = findUPar(v);
        if (ult_u == ult_v) return;
        if (size[ult_u] <= size[ult_v]) {
            parent[ult_u] = ult_v;
            size[ult_v] += size[ult_u];
        } else {
            parent[ult_v] = ult_u;
            size[ult_u] += size[ult_v];
        }
    }
    
    int getSize(int node) {
        return size[findUPar(node)];
    }
};

class Solution {
public:
    vector<pair<int, int>> adj = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};
    
    vector<int> hitBricks(vector<vector<int>>& grid, vector<vector<int>>& hits) {
        int m = grid.size();
        int n = grid[0].size();
        int roof = m * n; // Unique node to represent the "roof"
        
        DisjointSet ds(m * n + 1); // Include extra for roof
        
        // Step 1: Mark hits by decrementing in the grid
        for (auto &hit : hits) {
            grid[hit[0]][hit[1]]--;
        }
        
        auto index = [&](int x, int y) {
            return x * n + y;
        };
        
        for (int j = 0; j < n; j++) {
            if (grid[0][j] == 1) {
                ds.unionBySize(index(0, j), roof);
            }
        }
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    for (auto &[dx, dy] : adj) {
                        int ni = i + dx, nj = j + dy;
                        if (ni >= 0 && ni < m && nj >= 0 && nj < n && grid[ni][nj] == 1) {
                            ds.unionBySize(index(i, j), index(ni, nj));
                        }
                    }
                }
            }
        }
        
        // Process hits in reverse
        vector<int> res(hits.size());
        for (int i = hits.size() - 1; i >= 0; i--) {
            int x = hits[i][0], y = hits[i][1];
            
            // Skip if no brick was initially present
            if (++grid[x][y] != 1) continue;

            int prevRoofSize = ds.getSize(roof);

            // Connect the restored brick to neighbors
            for (auto &[dx, dy] : adj) {
                int ni = x + dx, nj = y + dy;
                if (ni >= 0 && ni < m && nj >= 0 && nj < n && grid[ni][nj] == 1) {
                    ds.unionBySize(index(x, y), index(ni, nj));
                }
            }
            
            // If in top row, connect to roof
            if (x == 0) {
                ds.unionBySize(index(x, y), roof);
            }
            
            // Calculate bricks that fell
            int newRoofSize = ds.getSize(roof);
            //to prevent addition of same component size again we take max with 0
            res[i] = max(0, newRoofSize - prevRoofSize - 1);  // Subtract 1 to exclude the brick itself
        }
        
        return res;
    }
};
