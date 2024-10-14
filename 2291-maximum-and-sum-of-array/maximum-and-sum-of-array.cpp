class Solution {
public:
    int dp[20][1<<10][1<<10];
    int solve(vector<int> &nums, int pos, int mask1,int mask2, int slots) {
        int n = nums.size();
        if(pos >= n) return 0;
        if(dp[pos][mask1][mask2] != -1) return dp[pos][mask1][mask2];
        int ma = INT_MIN;
        for(int i = 1;i < slots;i++) {
            if((mask1 & (1 << i)) == 0) {
                ma = max(ma,(nums[pos] & i) + solve(nums, pos+1,mask1|(1<<i), mask2, slots));
            }
            else if((mask2 & (1 << i)) == 0) {
                ma = max(ma,(nums[pos] & i) + solve(nums, pos+1,mask1, mask2|(1<<i), slots));
            }
        }
        return dp[pos][mask1][mask2] = ma;
    }
    int maximumANDSum(vector<int>& nums, int numSlots) {
        int n = nums.size();
        // vector<int> slots(numSlots+1,0);
        memset(dp,-1,sizeof(dp));
        return solve(nums,0,0,0,numSlots+1);
    }
};