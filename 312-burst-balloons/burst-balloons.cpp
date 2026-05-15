class Solution {
public:
    int dp[300][300];
    int solve(vector<int> &nums, int start, int end) {
        int n = nums.size();
        if(start > end) return 0;
        if(dp[start][end] != -1) return dp[start][end];
        int mxm = INT_MIN;
        for(int i = start; i <= end;i++) {
            int left = solve(nums, start, i-1);
            int right = solve(nums, i+1, end);
            mxm = max(mxm, nums[i] * (start-1 >= 0 ? nums[start-1] : 1) * (end+1 < n ? nums[end+1] : 1) + left + right);
        }
        return dp[start][end] = mxm;
    }
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        memset(dp,-1,sizeof(dp));
        return solve(nums, 0, n-1);
    }
};