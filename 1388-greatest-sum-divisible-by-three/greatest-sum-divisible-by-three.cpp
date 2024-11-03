class Solution {
public:
    int dp[40000][3];
    int solve(vector<int> &nums, int pos, int remainder) {
        int n = nums.size();
        if(pos >= n) {
            if(remainder == 0) return 0;
            return INT_MIN;
        }
        if(dp[pos][remainder] != -1) return dp[pos][remainder];
        int pick = nums[pos] + solve(nums, pos+1, (remainder+nums[pos]) % 3);
        int not_pick = solve(nums, pos+1, remainder);
        return dp[pos][remainder] = max(pick, not_pick);
    }
    int maxSumDivThree(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        return solve(nums,0,0);
    }
};