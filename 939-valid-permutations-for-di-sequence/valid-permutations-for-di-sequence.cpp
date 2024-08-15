class Solution {
public:
    int MOD = 1e9+7;
    long long dp[202][202];
    long long perms(string &s, int n, int pos, int prev, vector<bool> &visited) {
        if(pos >= n) return 1;
        if(dp[pos][prev] != -1) return dp[pos][prev];
        long long ans = 0;
        for(int i=0;i<=n;i++) {
            if(!visited[i]) {
                if(s[pos] == 'D' && prev > i) {
                    visited[i] = true;
                    ans = (ans + perms(s,n,pos+1,i,visited) % MOD) % MOD;
                    visited[i] = false;
                }
                if(s[pos] == 'I' && prev < i) {
                    visited[i] = true;
                    ans = (ans + perms(s,n,pos+1,i,visited) % MOD) % MOD;
                    visited[i] = false;
                }
            }
        }
        return dp[pos][prev] = ans;
    }
    int numPermsDISequence(string s) {
        int n = s.length();
        long long ans = 0;
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<=n;i++) {
            vector<bool> visited(n+1,false);
            visited[i] = true;
            ans = (ans + perms(s,n,0,i,visited) % MOD) % MOD;
        }
        return ans;
    }
};