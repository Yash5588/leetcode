class Solution {
public:
    int dp[20][1<<18];
    int solve(vector<int> &nums, int pos, int mask, int slots) {
        int n = nums.size();
        if(pos >= n) return 0;
        if(dp[pos][mask] != -1) return dp[pos][mask];
        int ma = INT_MIN;
        for(int i = 1;i < slots;i++) {
            int bit = 2*i-1,next_bit = 2*i-2;
            if((mask & (1 << bit)) == 0) {
                ma = max(ma,(nums[pos] & i) + solve(nums, pos+1,mask | (1<<bit),slots));
            }
            else if((mask & (1 << next_bit)) == 0) {
                ma = max(ma,(nums[pos] & i) + solve(nums, pos+1,mask | (1<<next_bit),slots));
            }
        }
        return dp[pos][mask] = ma;
    }
    int maximumANDSum(vector<int>& nums, int numSlots) {
        int n = nums.size();
        // vector<int> slots(numSlots+1,0);
        memset(dp,-1,sizeof(dp));
        return solve(nums,0,0,numSlots+1);
    }
};