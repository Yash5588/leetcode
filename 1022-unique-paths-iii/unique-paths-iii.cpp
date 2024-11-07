class Solution {
public:
    vector<pair<int,int>> adj = {{-1,0},{0,-1},{0,1},{1,0}};
    int solve(vector<vector<int>> &grid, int row, int col, int mask, int final_mask) {
        int m = grid.size();
        int n = grid[0].size();
        if(row < 0 || row >= m || col < 0 || col >= n) return 0;
        if(mask & (1 << (row*n + col))) return 0;
        mask |= (1 << (row*n + col));
        //add extra case that all empty cells are explored or not
        if(grid[row][col] == 2 && mask == final_mask) return 1;
        if(grid[row][col] == -1) return 0;
        int cnt = 0;
        for(int i = 0;i < 4;i++) {
            int new_row = row + adj[i].first;
            int new_col = col + adj[i].second;
            // int shift = new_row * n + new_col;
            cnt += solve(grid, new_row, new_col, mask, final_mask);
        }
        mask ^= (1 << (row*n + col));
        return cnt;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int final_mask = 0;
        pair<int,int> src = {-1,-1};
        //get destination mask to cover all paths
        for(int i = 0;i < m;i++) {
            for(int j = 0;j < n;j++) {
                if(grid[i][j] == 1) src = {i,j};
                else if(grid[i][j] == -1) continue;
                final_mask |=  (1 << (i*n + j));
            }
        }
        return solve(grid,src.first,src.second,0,final_mask);
    }
};