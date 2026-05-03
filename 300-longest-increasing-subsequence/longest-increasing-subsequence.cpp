class Solution {
public:
    int dp[2501][2501];
    int solve(vector<int> &nums, int idx, int prev) {
        int n = nums.size();
        if(idx >= n) return 0;
        if(dp[idx][prev] != -1) return dp[idx][prev];
        int pick = 0, not_pick = 0;
        if(prev >= n || nums[prev] < nums[idx]) {
            pick = 1 + solve(nums, idx+1, idx);
        }
        not_pick = solve(nums, idx+1, prev);
        return dp[idx][prev] = max(pick, not_pick);
    }
    int lengthOfLIS(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        return solve(nums, 0, nums.size());
    }
};