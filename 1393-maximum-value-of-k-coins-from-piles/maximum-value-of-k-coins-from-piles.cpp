class Solution {
public:
    long long dp[1010][2010];
    long long solve(vector<vector<int>> &piles, long long k, int pos) {
        //we can't move forward if either piles are over or k is exhausted
        if(pos >= piles.size() || k == 0) return 0;
        if(dp[pos][k] != -1) return dp[pos][k];

        //this is case where we don't consider current pile
        long long not_taken = solve(piles,k,pos+1);

        //we consider taking from current pile
        long long taken = 0,sum = 0;
        //min(k,current pile size) becoz if either k is larger than current pile max to max we can take whole current pile otherwise if k is smaller than current pile we can only take k elements from current pile
        for(int i=0;i<min(k,(long long)piles[pos].size());i++) {
            //consider taking all cases 1,2,3...  from current pile
            sum += piles[pos][i];
            //k-(i+1) we have taken i+1 coins from k
            taken = max(taken, sum + solve(piles,k-(i+1),pos+1));
        }
        //max of both taken and not taken
        return dp[pos][k] = max(not_taken,taken);
    }
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        int n = piles.size();
        memset(dp,-1,sizeof(dp));
        return solve(piles,k,0);
    }
};