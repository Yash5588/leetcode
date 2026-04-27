class Solution {
public:
    int dp[10001][12];
    int solve(vector<int> &coins, int amount, int idx) {
        if(amount == 0) {
            return 0;
        }
        if(idx >= coins.size()) {
            return 1e9;
        }
        if(dp[amount][idx] != -1) return dp[amount][idx];
        int pick = 1e9,not_pick = 1e9;
        if(amount >= coins[idx]) {
            pick = 1 + solve(coins, amount-coins[idx], idx);
        }
        not_pick = solve(coins, amount, idx+1);
        return dp[amount][idx] = min(pick, not_pick);
    }
    int coinChange(vector<int>& coins, int amount) {
        // sort(coins.begin(),coins.end(),greater<int>());
        memset(dp,-1,sizeof(dp));
        int res = solve(coins, amount, 0);
        return (res >= 1e9) ? -1 : res;
    }
};