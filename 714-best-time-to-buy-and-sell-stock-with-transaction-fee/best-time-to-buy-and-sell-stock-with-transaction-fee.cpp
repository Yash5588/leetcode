class Solution {
public:
    int dp[50000][2];
    int solve(vector<int> &prices, int fee, int pos, bool isBuy) {
        int n = prices.size();
        if(pos >= n) return 0;
        if(dp[pos][isBuy] != -1) return dp[pos][isBuy];
        int skip = solve(prices, fee, pos+1, isBuy);
        if(isBuy) {
            int sell = (prices[pos] + solve(prices, fee, pos+1, false)) - fee;
            return dp[pos][isBuy] = max(skip, sell);
        }
        int buy = -prices[pos] + solve(prices, fee, pos+1, true);
        return dp[pos][isBuy] = max(skip, buy);
    }

    int maxProfit(vector<int> &prices, int fee) {
        int n = prices.size();
        memset(dp,-1,sizeof(dp));
        return solve(prices, fee, 0, false);
    }
};