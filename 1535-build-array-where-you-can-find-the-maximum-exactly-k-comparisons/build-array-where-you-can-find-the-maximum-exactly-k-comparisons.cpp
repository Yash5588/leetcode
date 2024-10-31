class Solution {
public:
    int mod = 1e9+7;
    long long dp[51][51][101];
    long long solve(int n, int pos, int m, int k, int prev) {
        if(pos >= n) {
            if(k == 0) return 1;
            return 0;
        }
        if(dp[pos][k][prev] != -1) return dp[pos][k][prev];
        long long cnt = 0;
        for(int i = 1;i <= m;i++) {
            if(prev < i) {
                if(k > 0) {
                    cnt = (cnt + solve(n,pos+1,m,k-1,i)%mod)%mod;
                }
            }
            else cnt =  (cnt + solve(n,pos+1,m,k,prev)%mod)%mod;
        }
        return dp[pos][k][prev] = cnt;
    }
    int numOfArrays(int n, int m, int k) {
        memset(dp,-1,sizeof(dp));
        return solve(n,0,m,k,0)%mod;
    }
};