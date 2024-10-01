class Solution {
public:
    int dp[100000];
    int solve(vector<vector<int>> &vec, vector<int> &start, int pos) {
        int n = start.size();
        if(pos >= n) return 0;
        if(dp[pos] != -1) return dp[pos];
        int ind = lower_bound(start.begin(),start.end(),vec[pos][1]) - start.begin();
        int pick = vec[pos][2] + solve(vec,start,ind);
        int not_pick = solve(vec,start,pos+1);
        return dp[pos] = max(pick,not_pick);
    }
    int jobScheduling(vector<int>& start, vector<int>& end, vector<int>& profit) {
        int n = start.size();
        vector<vector<int>> vec;
        for(int i = 0;i < n;i++) {
            vec.push_back({start[i],end[i],profit[i]});
        }
        sort(vec.begin(),vec.end());
        sort(start.begin(),start.end());
        memset(dp,-1,sizeof(dp));
        return solve(vec,start,0);
    }
};