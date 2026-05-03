class Solution {
public:
    int mxm = 0;
    int dp[300][300];
    int solve(vector<vector<char>> &grid, int row, int col) {
        int m = grid.size();
        int n = grid[0].size();
        if(row >= m || col >= n) return 0;
        if(grid[row][col] == '0') return 0;
        if(dp[row][col] != -1) return dp[row][col];
        return dp[row][col] = (grid[row][col]-'0') + min({
            solve(grid, row+1, col),
            solve(grid, row, col+1),
            solve(grid, row+1, col+1)
        });
    }
    int maximalSquare(vector<vector<char>>& grid) {
        memset(dp,-1,sizeof(dp));
        for(int i = 0;i < grid.size();i++) {
            for(int j = 0;j < grid[0].size();j++) {
                mxm = max(mxm, solve(grid, i, j));
            }
        }
        return mxm*mxm;
    }
};