class Solution {
public:
    int dp[100];
    int solve(int n) {
        if(n == 0) {
            // if(k >= 2) return 1;
            return 1;
        }
        if(dp[n] != -1) return dp[n];
        int mxm = INT_MIN;
        for(int i = n;i >= 1;i--) {
            mxm = max(mxm, i * solve(n-i));
        }
        return dp[n] = mxm;
    }
    int integerBreak(int n) {
        memset(dp,-1,sizeof(dp));
        int mxm = INT_MIN;
        for(int i = n-1;i >= 1;i--) {
            mxm = max(mxm, i * solve(n-i));
        }
        return mxm;
    }
};