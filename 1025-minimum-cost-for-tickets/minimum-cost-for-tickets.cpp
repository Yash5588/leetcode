class Solution {
public:
    int dp[366];
    int solve(vector<int> &days, vector<int> &costs, int idx) {
        int n = days.size();
        if(idx >= n) return 0;
        if(dp[idx] != -1) return dp[idx];
        int mnm = INT_MAX;
        int one = days[idx]+1, seven = days[idx]+7, thirty = days[idx] + 30;
        int i=idx,j=idx,k=idx;
        while(i < n && days[i] < one) i++;
        while(j < n && days[j] < seven) j++;
        while(k < n && days[k] < thirty) k++;
        int one_pick = costs[0] + solve(days,costs,i);
        int seven_pick = costs[1] + solve(days,costs,j);
        int thirty_pick = costs[2] + solve(days,costs,k);
        return dp[idx] = min({one_pick, seven_pick, thirty_pick});
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        memset(dp,-1,sizeof(dp));
        return solve(days, costs, 0);
    }
};