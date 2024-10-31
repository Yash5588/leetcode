class Solution {
public:
    long long dp[51][101][51];
    int mod = 1e9+7;
    long long arrays(int idx, int mxm, int cost, int n, int m, int k) {
        if(idx==n) {
            if(cost==k) return 1;
            return 0;
        }
        if(dp[idx][mxm][cost]!=-1) return dp[idx][mxm][cost];
        long long count=0;
        for(int i=1; i<=m; i++) {
            if(i>mxm) {
                count = ((count%mod) + (arrays(idx+1, i, cost+1, n, m, k)%mod))%mod;
            }
            else {
                count = ((count%mod) + (arrays(idx+1, mxm, cost, n, m, k)%mod))%mod;
            }
            count = count%mod;
        }
        return dp[idx][mxm][cost] = count;
    }
    int numOfArrays(int n, int m, int k) {
        memset(dp,-1,sizeof(dp));
        return arrays(0,0,0,n, m,k)%mod;
    }
};