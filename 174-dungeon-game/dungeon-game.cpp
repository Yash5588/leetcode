class Solution {
public:
    long long dp[200][200];
    long long solve(vector<vector<int>> &dungeon, int row, int col) {
        int m = dungeon.size();
        int n = dungeon[0].size();
        if(row >= m || col >= n) return INT_MAX;
        if(dp[row][col] != -1) return dp[row][col];
        if(row == m-1 && col == n-1) {
            if(dungeon[row][col] > 0) return 1;
            return abs(dungeon[row][col]) + 1;
        }
        int right = solve(dungeon, row, col+1);
        int down = solve(dungeon, row+1, col);
        int res = min(right, down) - dungeon[row][col];
        return dp[row][col] = (res > 0) ? res : 1;

    }
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        memset(dp,-1,sizeof(dp));
        return solve(dungeon, 0, 0);
    }
};