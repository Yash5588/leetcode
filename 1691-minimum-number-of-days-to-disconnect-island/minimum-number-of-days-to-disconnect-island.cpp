class Solution {
public:
    vector<pair<int,int>> adj = {{-1,0},{0,-1},{0,1},{1,0}};
    void dfs(vector<vector<int>> &grid, int row, int col, vector<vector<bool>> &visited) {
        int n = grid.size();
        int m = grid[0].size();
        if(row < 0 || row >= n || col < 0 || col >= m || visited[row][col]) {
            return;
        }
        if(grid[row][col] == 0) return;
        visited[row][col] = true;
        for(int i = 0;i < 4;i++) {
            int new_row = row + adj[i].first;
            int new_col = col + adj[i].second;
            dfs(grid,new_row,new_col,visited);
        }
    }
    int islands(vector<vector<int>> &grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> visited(n, vector<bool> (m,false));
        int cnt = 0;
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                if(grid[i][j] == 1 && !visited[i][j]) {
                    cnt++;
                    dfs(grid,i,j,visited);
                }
            }
        }
        return cnt;
    }
    int minDays(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        if(islands(grid) != 1) return 0;
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                if(grid[i][j] == 1) {
                    grid[i][j] = 0;
                    if(islands(grid) != 1) return 1;
                    grid[i][j] = 1;
                }
            }
        }
        return 2;
    }
};