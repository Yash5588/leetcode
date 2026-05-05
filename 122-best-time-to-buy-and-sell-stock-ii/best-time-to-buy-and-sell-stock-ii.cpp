class Solution {
public:
    int dp[30002][2];

    int solve(vector<int> &prices, int idx, int isBuy) {
        if(idx >= prices.size()) return 0;

        if(dp[idx][isBuy] != -1) return dp[idx][isBuy];

        int profit = 0;

        if(isBuy == 0) {
            // buy
            profit = max(
                -prices[idx] + solve(prices, idx+1, 1),
                solve(prices, idx+1, 0)
            );
        } else {
            // sell
            profit = max(
                prices[idx] + solve(prices, idx+1, 0),
                solve(prices, idx+1, 1)
            );
        }

        return dp[idx][isBuy] = profit;
    }

    int maxProfit(vector<int>& prices) {
        memset(dp, -1, sizeof(dp));
        return solve(prices, 0, 0);
    }
};