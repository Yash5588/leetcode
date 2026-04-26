class Solution {
public:
    int dp[601][101][101];
    int solve(vector<string> &strs, int m, int n, int idx) {
        int size = strs.size();
        if(m < 0 || n < 0) return -1e5;
        if(idx >= size) {
            return 0;
        }
        if(dp[idx][m][n] != -1) return dp[idx][m][n];
        int pick = -1e5, not_pick = -1e5;
        int ones = 0,zeros = 0;
        for(auto &x : strs[idx]) {
            if(x == '0') zeros++;
            else ones++;
        }
        return dp[idx][m][n] = max(1 + solve(strs, m-zeros, n-ones, idx+1), solve(strs, m, n, idx+1));

    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        memset(dp,-1,sizeof(dp));
        return solve(strs, m, n, 0);
    }
};