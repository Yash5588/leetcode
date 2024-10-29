class Solution {
public:
    vector<pair<int,int>> adj = {{-1,0}, {0,-1}, {0,1}, {1,0}};
    int dfs(vector<vector<int>> &grid, int row, int col, vector<vector<bool>> &visited) {
        int m = grid.size();
        int n = grid[0].size();
        if(row < 0 || row >= m || col < 0 || col >= n || visited[row][col]) return 0;
        if(grid[row][col] == 0) return 0;
        int cnt = 1;
        visited[row][col] = true;
        for(int i = 0;i < 4;i++) {
            int new_row = row + adj[i].first;
            int new_col = col + adj[i].second;
            cnt += dfs(grid,new_row,new_col,visited);
        }
        return cnt;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n,false));
        int c = 0;
        int ma = 0;
        for(int i = 0;i < m;i++) {
            for(int j = 0;j < n;j++) {
                if(grid[i][j] == 1 && !visited[i][j]) {
                    ma = max(ma, dfs(grid,i,j,visited));
                }
            }
        }
        return ma;
    }
};