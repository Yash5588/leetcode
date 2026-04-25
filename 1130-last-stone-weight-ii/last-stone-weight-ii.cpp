class Solution {
public:
    int dp[30][10000];
    int solve(vector<int> &stones, int idx, int sum) {
        if(sum < 0) return INT_MAX;
        if(idx >= stones.size()) {
            return sum;
        }
        if(dp[idx][sum] != -1) return dp[idx][sum];
        return dp[idx][sum] = min(solve(stones,idx+1,sum-stones[idx]), solve(stones,idx+1,sum)); 
    }
    int lastStoneWeightII(vector<int>& stones) {
        int n = stones.size();
        int total = accumulate(stones.begin(),stones.end(),0);
        int half = total/2;
        memset(dp,-1,sizeof(dp));
        int leftover = solve(stones,0,half);
        int firstSet = half - leftover;
        int secondSet = total - firstSet;
        return secondSet - firstSet;
    }
};