class Solution {
public:
    int dp[70][70][70][70];
    int solve(vector<vector<int>> &grid, int row1, int col1, int row2, int col2) {
        int n = grid.size();
        int m = grid[0].size();
        if(row1 >= n || row2 >= n || col1 >= m || col2 >= m) return INT_MIN;
        if(col1 < 0 || col2 < 0) return INT_MIN;
        //why we are blocking same block path?
        //becoz think of it if both robots pick same block will it result in max
        //there might be a block which might have less val
        //but if they both pick 5 suppose
        //the result of that row is 5 
        //but if there is another of 1 
        //then we can pick 5 and 1 results in 6
        //so there always exists a better or same result(all are 0 in a case) if we ignore same block
        if(row1 == row2 && col1 == col2) return INT_MIN;
        if(row1 == n-1 && row2 == n-1) {
            return grid[row1][col1] + grid[row2][col2];
        }
        if(dp[row1][col1][row2][col2] != -1) return dp[row1][col1][row2][col2];
        int ma = INT_MIN;
        for(int first = -1;first <= 1;first++) {
            for(int second = -1;second <= 1;second++) {
                ma = max(ma, grid[row1][col1] + grid[row2][col2] + solve(grid, row1+1,col1+first,row2+1,col2+second));
            }
        }
        return dp[row1][col1][row2][col2] = ma;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        memset(dp,-1,sizeof(dp));
        return solve(grid,0,0,0,m-1);
    }
};