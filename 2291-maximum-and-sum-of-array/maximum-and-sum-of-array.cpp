class Solution {
public:
    int dp[18][1<<10][1<<10];
    int maxm(vector<int>& nums, int mask1,int mask2, int idx1, int slots) {
        int n = nums.size();
        if(idx1>=n) return 0;
        if(dp[idx1][mask1][mask2]!= -1) return dp[idx1][mask1][mask2];
        int mxm=INT_MIN;
        for(int i=0; i<slots; i++) {
            if((mask1 & (1 << i)) == 0) mxm =  max(mxm, (nums[idx1]&i)+maxm(nums,mask1 | (1 << i),mask2,idx1+1,slots));
            else if((mask2 & (1 << i)) == 0) mxm = max(mxm, (nums[idx1]&i)+maxm(nums,mask1,mask2|(1<<i),idx1+1,slots));
        }
        return dp[idx1][mask1][mask2] = mxm;
    }
    int maximumANDSum(vector<int>& nums, int numSlots) {
        memset(dp,-1,sizeof(dp));
        int n = nums.size();
        return maxm(nums,0,0,0, numSlots+1);
    }
};