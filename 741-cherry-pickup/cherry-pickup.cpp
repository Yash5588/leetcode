class Solution {
public:
    int dp[50][50][50][50];
    int solve(vector<vector<int>> &grid, int row1, int col1, int row2, int col2) {
        int n = grid.size();
        //if any one of both routes reaches end
        if(row1 == n-1 && col1 == n-1) {
            if(grid[row1][col1] == 1) return 1;
            if(grid[row1][col1] == -1) return INT_MIN;
            return 0;
        }
        if(row2 == n-1 && col2 == n-1) {
            if(grid[row2][col2] == 1) return 1;
            if(grid[row2][col2] == -1) return INT_MIN;
            return 0;
        }
        //if any route out of bounds
        if(row1 >= n || col1 >= n || row2 >= n || col2 >= n) return INT_MIN;
        //if path is restricted
        if(grid[row1][col1] == -1 || grid[row2][col2] == -1) return INT_MIN;
        if(dp[row1][col1][row2][col2] != -1) return dp[row1][col1][row2][col2];
        int ans = 0;
        //if our both paths align at same points consider only for one path the current cherry
        if(row1 == row2 && col1 == col2) {
            ans += (grid[row1][col1] == 1);
        }
        else {
            //otherwise consider both paths cherries separately
            ans += (grid[row1][col1] == 1);
            ans += (grid[row2][col2] == 1);
        }
        //all routes
        int downdown = solve(grid,row1+1,col1,row2+1,col2);
        int downright = solve(grid,row1+1,col1,row2,col2+1);
        int rightdown = solve(grid,row1,col1+1,row2+1,col2);
        int rightright = solve(grid,row1,col1+1,row2,col2+1);
        //max of all routes
        return dp[row1][col1][row2][col2] = ans + max({downdown,downright,rightdown,rightright});
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        memset(dp,-1,sizeof(dp));
        int ans = solve(grid,0,0,0,0);
        return max(ans,0);
    }
};