class Solution {
public:
    int dp[30002][2];
    int solve(vector<int> &prices, int idx, bool isBuy) {
        int n = prices.size();
        if(idx >= n) {
            return 0;
        }
        if(dp[idx][isBuy] != -1) return dp[idx][isBuy];
        int mxm = INT_MIN;
        if(!isBuy) {
            mxm = max(mxm, -prices[idx] + solve(prices, idx+1, !isBuy));
        }
        else {
            mxm = max(mxm, prices[idx] + solve(prices, idx+1, !isBuy));
        }
        mxm = max(mxm, solve(prices, idx+1, isBuy));
        return dp[idx][isBuy] = mxm;

    }
    int maxProfit(vector<int>& prices) {
        memset(dp,-1,sizeof(dp));
        return solve(prices, 0, false);
    }
};