class Solution {
public:
    int dp[1000][2][101];
    int solve(vector<int> &prices, int idx, bool isBuy, int k) {
        int n = prices.size();
        if(k < 0) return -1e5;
        if(idx >= n) {
            return 0;
        }
        if(dp[idx][isBuy][k] != -1) return dp[idx][isBuy][k];
        int mxm = INT_MIN;
        if(!isBuy) {
            mxm = max(mxm, -prices[idx] + solve(prices, idx+1, !isBuy, k));
        }
        else {
            mxm = max(mxm, prices[idx] + solve(prices, idx+1, !isBuy, k-1));
        }
        mxm = max(mxm, solve(prices, idx+1, isBuy, k));
        return dp[idx][isBuy][k] = mxm;

    }
    int maxProfit(int k, vector<int>& prices) {
        memset(dp,-1,sizeof(dp));
        return solve(prices, 0, false, k);
    }
};