class Solution {
public:
    int dp[12][1<<13];
    int solve(vector<int> &nums, int prevInd, int mask) {
        int n = nums.size();
        if(mask == (1 << n)-1) {
            return 1;
        }
        if(dp[prevInd][mask] != -1) return dp[prevInd][mask];
        int cnt = 0;
        for(int i = 0;i < n;i++) {
            if(mask & (1 << i)) continue;
            if(i > 0 && nums[i] == nums[i-1] && !(mask & (1 << (i-1)))) continue;
            if(int(sqrt(nums[prevInd] + nums[i])) == sqrt(nums[prevInd] + nums[i])) {
                cnt += solve(nums, i, mask | (1 << i));
            }
        }
        return dp[prevInd][mask] = cnt;
    }
    int numSquarefulPerms(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;
        sort(nums.begin(),nums.end());
        memset(dp,-1,sizeof(dp));
        cnt += solve(nums,0,1<<0);
        for(int i = 1;i < n;i++) {
            if(nums[i] != nums[i-1]) {
                cnt += solve(nums,i,1<<i);
            }
        }
        return cnt;
    }
};