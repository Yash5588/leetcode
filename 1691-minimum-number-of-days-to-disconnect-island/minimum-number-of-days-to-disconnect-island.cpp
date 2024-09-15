class Solution {
public:
    vector<pair<int,int>> adj = {{-1,0},{0,-1},{0,1},{1,0}};
    void bfs(vector<vector<int>> &grid, int row, int col, vector<vector<bool>> &visited) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int,int>> que;
        que.push({row,col});
        visited[row][col] = true;
        while(!que.empty()) {
            int curr_row = que.front().first;
            int curr_col = que.front().second;
            que.pop();
            for(int i = 0;i < 4;i++) {
                int new_row = curr_row + adj[i].first;
                int new_col = curr_col + adj[i].second;
                if(new_row >= 0 && new_row < n && new_col >= 0 && new_col < m) {
                    if(grid[new_row][new_col] == 1 && !visited[new_row][new_col]) {
                        que.push({new_row,new_col});
                        visited[new_row][new_col] = true;
                    }
                }
            }
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
                    bfs(grid,i,j,visited);
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