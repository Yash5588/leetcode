class Solution {
public:
    int dp[200][200];
    int solve(vector<vector<int>> &grid, int row, int col) {
        int m = grid.size();
        int n = grid[0].size();
        if(row >= m || col >= n) return 1e6;
        if(row == m-1 && col == n-1) return grid[row][col];
        if(dp[row][col] != -1) return dp[row][col];
        return dp[row][col] = grid[row][col] + min(solve(grid,row+1,col),solve(grid,row,col+1));
    }
    int minPathSum(vector<vector<int>>& grid) {
        memset(dp,-1,sizeof(dp));
        return solve(grid,0,0);
    }
};