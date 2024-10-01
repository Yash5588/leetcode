class Solution {
public:
    long long dp[100][21][100];
    long long solve(vector<vector<int>> &cost, vector<int> &houses, int target, int pos, int prev, int neighbours) {
        int m = cost.size();
        int n = cost[0].size();
        if(pos >= m) {
            if(neighbours == target) return 0;
            return INT_MAX;
        }
        if(dp[pos][prev][neighbours] != -1) return dp[pos][prev][neighbours];
        long long pick = 0,not_pick = 0;
        if(houses[pos] == 0) {
            long long mi = INT_MAX;
            for(int i = 0;i < n;i++) {
                if(pos == 0 || prev != i + 1) {
                    mi = min(mi, (long long)cost[pos][i] + solve(cost,houses,target,pos+1,i+1,neighbours+1));
                }
                else {
                    mi = min(mi, (long long)cost[pos][i] + solve(cost,houses,target,pos+1,prev,neighbours));
                }
            }
            return dp[pos][prev][neighbours] = mi;
        }
        else {
            if(pos == 0 || prev != houses[pos]) {
                return dp[pos][prev][neighbours] = solve(cost,houses,target,pos+1,houses[pos],neighbours+1);
            }
            return dp[pos][prev][neighbours] = solve(cost,houses,target,pos+1,prev,neighbours);
        }
    }
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        memset(dp,-1,sizeof(dp));
        long long res = solve(cost,houses,target,0,0,0);
        if(res == INT_MAX) return -1;
        return res;
    }
};