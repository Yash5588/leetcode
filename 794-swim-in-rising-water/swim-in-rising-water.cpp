class Solution {
public:
    vector<pair<int,int>> adj = {{-1,0},{0,-1},{0,1},{1,0}};
    void dfs(vector<vector<int>> &grid, vector<vector<bool>> &visited, int mid, int row, int col) {
        int n = grid.size();
        if(row < 0 || row >= n || col < 0 || col >= n || visited[row][col]) {
            return;
        }
        if(grid[row][col] > mid) return;
        visited[row][col] = true;
        for(int i = 0;i < 4;i++) {
            int new_row = row + adj[i].first;
            int new_col = col + adj[i].second;
            dfs(grid,visited,mid,new_row,new_col);
        }
    }
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        int low = 0,high = n*n - 1;
        int ans = -1;
        while(low <= high) {
            int mid = low + (high - low)/2;
            vector<vector<bool>> visited(n,vector<bool> (n,false));
            dfs(grid,visited,mid,0,0);
            if(visited[n-1][n-1]) {
                ans = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
            visited.clear();
        }
        return ans;
    }
};