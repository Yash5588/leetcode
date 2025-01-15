class Solution {
public:
    long long dp[502][502][3];
    long long solve(vector<vector<int>>& coins, int row, int col, int prevent) {
        int m = coins.size();
        int n = coins[0].size();
        if(row >= m || col >= n) return INT_MIN;
        if(row == m-1 && col == n-1) {
            if(coins[row][col] >= 0) return coins[row][col];
            if(prevent > 0) return 0;
            return coins[row][col];
        }
        if(dp[row][col][prevent] != INT_MIN) return dp[row][col][prevent];
        if(coins[row][col] >= 0) {
            return dp[row][col][prevent] = coins[row][col] + max(solve(coins, row+1, col, prevent), solve(coins, row, col+1, prevent));
        }
        long long prevented = INT_MIN;
        if(prevent > 0) {
            prevented = max(solve(coins, row+1, col, prevent-1), solve(coins, row, col+1, prevent-1));
        }
        long long not_prevented = coins[row][col] + max(solve(coins, row+1, col, prevent), solve(coins, row, col+1, prevent));
        return dp[row][col][prevent] = max(prevented, not_prevented);
    }
    int maximumAmount(vector<vector<int>>& coins) {
        int m = coins.size();
        int n = coins[0].size();
        for(int i = 0;i < 501;i++) {
            for(int j = 0;j < 501;j++) {
                for(int k = 0;k < 3;k++) {
                    dp[i][j][k] = INT_MIN;
                }
            }
        }
        return solve(coins, 0, 0, 2);
    }
};