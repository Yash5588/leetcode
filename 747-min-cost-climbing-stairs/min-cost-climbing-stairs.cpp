class Solution {
public:
    int dp[1000];
    int solve(vector<int> &cost, int idx) {
        if(idx >= cost.size()) return 0;
        if(dp[idx] != -1) return dp[idx];
        return dp[idx] = cost[idx] + min(solve(cost,idx+1),solve(cost,idx+2)); 

    }
    int minCostClimbingStairs(vector<int>& cost) {
        memset(dp,-1,sizeof(dp));
        return min(solve(cost,0), solve(cost,1));
    }
};