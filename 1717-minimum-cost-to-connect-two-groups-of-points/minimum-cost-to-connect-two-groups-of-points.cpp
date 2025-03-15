class Solution {
public:
    int dp[12][1 << 12];
    int solve(vector<vector<int>>& cost, vector<int> min_cost2, int pos, int mask2) {
        int size1 = cost.size();
        int size2 = cost[0].size();
        if(pos >= size1) {
            int rem_cost = 0;
            for(int j = 0;j < size2;j++) {
                if(mask2 & (1 << j)) continue;
                rem_cost += min_cost2[j];
            }
            return rem_cost;
        }
        
        if(dp[pos][mask2] != -1) return dp[pos][mask2];
        int mnm = 1e5;
        for(int j = 0;j < size2;j++) {
            mnm = min(mnm, cost[pos][j] + solve(cost, min_cost2, pos+1, mask2 | (1 << j)));
        }
        return dp[pos][mask2] = mnm;
    }
    int connectTwoGroups(vector<vector<int>>& cost) {
        int size1 = cost.size();
        int size2 = cost[0].size();
        vector<int> min_cost2(size2,INT_MAX);
        //precompute for all the nodes in 2nd group if they are left out
        for(int j = 0;j < size2;j++) {
            for(int i = 0;i < size1;i++) {
                min_cost2[j] = min(min_cost2[j], cost[i][j]);
            }
        }
        memset(dp,-1,sizeof(dp));
        return solve(cost,min_cost2, 0, 0);
    }
};