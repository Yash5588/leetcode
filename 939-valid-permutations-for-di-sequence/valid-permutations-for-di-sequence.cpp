class Solution {
public:
    int MOD = 1e9+7;
    long long dp[202][202];
    long long perms(string &s, int n, int pos, int prev, vector<bool> &visited) {
        if(pos >= n) return 1; // if you can reach till end then you have found one valid permutation
        if(dp[pos][prev] != -1) return dp[pos][prev];
        long long ans = 0;
        //we have to fix rest elements in permutation so we need to check all elements for next position
        for(int i=0;i<=n;i++) {
            //if it not visited
            if(!visited[i]) {
                //check whether current element satisfies these conditions
                if(s[pos] == 'D' && prev > i) {
                    visited[i] = true;
                    //then consider it and go for next position and current will become previous
                    ans = (ans + perms(s,n,pos+1,i,visited) % MOD) % MOD;

                    //will backtracking make sure to revoke changes
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
        //we need to fix the starting element in permutation and check how many 
        //combinations are satisfied
        for(int i=0;i<=n;i++) {

            //visited array to keep track of not considering the element in permutation if it is
            //previously visited
            vector<bool> visited(n+1,false);
            visited[i] = true;
            //we need to consider pos and prev variables
            //pos to keep track of string s
            //prev to keep track of previously considered element
            ans = (ans + perms(s,n,0,i,visited) % MOD) % MOD;
        }
        return ans;
    }
};