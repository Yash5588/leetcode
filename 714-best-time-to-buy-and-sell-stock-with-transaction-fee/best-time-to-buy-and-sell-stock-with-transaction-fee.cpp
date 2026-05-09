class Solution {
public:
    int dp[50000][2];
    int solve(vector<int> &prices,int fee, int idx, bool isBuy) {
        int n = prices.size();
        if(idx >= n) {
            return 0;
        }
        if(dp[idx][isBuy] != -1) return dp[idx][isBuy];
        int pick = 0;
        if(!isBuy) {
            pick = -prices[idx] + solve(prices,fee, idx+1, !isBuy);
        }
        else {
            pick = prices[idx] - fee + solve(prices,fee ,idx+1, !isBuy);
        }
        int not_pick = solve(prices, fee, idx+1, isBuy);
        return dp[idx][isBuy] = max(pick, not_pick);
    }
    int maxProfit(vector<int>& prices, int fee) {
        memset(dp,-1,sizeof(dp));
        return solve(prices, fee, 0, false);
    }
};