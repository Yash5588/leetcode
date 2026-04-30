class Solution {
public:
    int dp[100][100];
    int solve(int n, int k) {
        if(n == 0) {
            if(k >= 2) return 1;
            return -1;
        }
        if(dp[n][k] != -1) return dp[n][k];
        int mxm = INT_MIN;
        for(int i = 1;i <= n;i++) {
            mxm = max(mxm, i * solve(n-i,k+1));
        }
        return dp[n][k] = mxm;
    }
    int integerBreak(int n) {
        memset(dp,-1,sizeof(dp));
        return solve(n, 0);
    }
};