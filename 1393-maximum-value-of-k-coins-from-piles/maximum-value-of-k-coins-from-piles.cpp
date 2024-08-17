class Solution {
public:
    long long dp[1010][2010];
    long long solve(vector<vector<int>> &piles, long long k, int pos) {
        if(pos >= piles.size() || k == 0) return 0;
        if(dp[pos][k] != -1) return dp[pos][k];
        long long not_taken = solve(piles,k,pos+1);
        long long taken = 0,sum = 0;
        for(int i=0;i<min(k,(long long)piles[pos].size());i++) {
            sum += piles[pos][i];
            taken = max(taken, sum + solve(piles,k-(i+1),pos+1));
        }
        return dp[pos][k] = max(not_taken,taken);
    }
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        int n = piles.size();
        memset(dp,-1,sizeof(dp));
        return solve(piles,k,0);
    }
};