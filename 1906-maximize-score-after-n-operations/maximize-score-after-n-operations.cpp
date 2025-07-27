class Solution {
public:
    long long dp[1<<14][10];
    long long solve(vector<int> &nums, int mask, int idx) {
        int n = nums.size();
        if(idx >= n/2+1) return 0;
        if(dp[mask][idx] != -1) return dp[mask][idx];
        long long mxm = 0;
        for(int i = 0;i < n-1;i++) {
            if(mask & (1<<i)) continue;
            long long new_mask = mask | (1<<i);
            for(int j = i+1;j < n;j++) {
                if(mask & (1<<j)) continue;
                mxm = max(mxm, (idx * gcd(nums[i],nums[j])) + solve(nums, new_mask | (1<<j), idx+1));
            }
        }
        return dp[mask][idx] = mxm;
    }
    int maxScore(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        return solve(nums, 0, 1);
    }
};