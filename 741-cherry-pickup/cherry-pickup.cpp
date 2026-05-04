class Solution {
public:
    int dp[50][50][50];
    int solve(vector<vector<int>> &grid, int row1, int col1, int col2) {
        int n = grid.size();
        int row2 = row1 + col1 - col2;
        if(row1 >= n || col1 >= n || row2 >= n || col2 >= n) return -1e5;
        if(row1 == n-1 && col1 == n-1 && row2 == n-1 && col2 == n-1) return grid[row1][col1];
        if(grid[row1][col1] == -1 || grid[row2][col2] == -1) return -1e5;
        if(dp[row1][col1][col2] != -1) return dp[row1][col1][col2];
        int ans = grid[row1][col1];
        if(row1 != row2 && col1 != col2) ans += grid[row2][col2];
        int rr = solve(grid, row1, col1+1, col2+1);
        int rd = solve(grid, row1+1, col1, col2+1);
        int dr = solve(grid, row1+1, col1, col2);
        int dd = solve(grid, row1, col1+1, col2);
        return dp[row1][col1][col2] = ans + max({rr, rd, dr, dd});
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        memset(dp,-1,sizeof(dp));
        return max(solve(grid, 0, 0, 0),0);
    }
};