class Solution {
public:
    int dp[(int)1e5][2][3];
    int solve(vector<int> &prices, int idx, bool isBuy, int limit) {
        int n = prices.size();
        if(limit < 0) return -1e5;
        if(idx >= n) {
            return 0;
        }
        if(dp[idx][isBuy][limit] != -1) return dp[idx][isBuy][limit];
        int mxm = INT_MIN;
        if(!isBuy) {
            mxm = max(mxm, -prices[idx] + solve(prices, idx+1, !isBuy, limit));
        }
        else {
            mxm = max(mxm, prices[idx] + solve(prices, idx+1, !isBuy, limit-1));
        }
        mxm = max(mxm, solve(prices, idx+1, isBuy, limit));
        return dp[idx][isBuy][limit] = mxm;

    }
    int maxProfit(vector<int>& prices) {
        memset(dp,-1,sizeof(dp));
        return solve(prices, 0, false, 2);
    }
};