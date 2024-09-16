class Solution {
public:
    int dp[201][201];
    int solve(vector<vector<int>> &grid, int row, int prev_col) {
        int n = grid.size();
        if(row >= n) return 0;
        if(dp[row][prev_col] != -1) return dp[row][prev_col];
        int mi = 100000;
        for(int col = 0;col < n;col++) {
            if(col != prev_col) {
                mi = min(mi, grid[row][col] + solve(grid,row+1,col));
            }
        }
        return dp[row][prev_col] = mi;
    }
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int mi = 100000;
        memset(dp,-1,sizeof(dp));
        for(int col = 0;col < n;col++) {
            mi = min(mi, grid[0][col] + solve(grid,1,col));
        }
        return mi;
    }
};