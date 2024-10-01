class Solution {
public:
    int dp[100001][200];
    int solve(int k, int n) {
        if(n == 0) return 0;
        if(n == 1) return 1;
        if(k == 1) return n;
        if(dp[n][k] != -1) return dp[n][k];
        int ans = INT_MAX;
        int low = 1,high = n;
        while(low <= high) {
            int mid = low + (high - low)/2;
            int top = solve(k,n-mid);
            int bottom = solve(k-1,mid-1);
            ans = min(ans, 1 + max(top,bottom));
            if(top < bottom) {
                high = mid - 1;
            }
            else low = mid + 1;
        }
        return dp[n][k] = ans;
    }
    int superEggDrop(int k, int n) {
        memset(dp,-1,sizeof(dp));
        return solve(k,n);
    }
};