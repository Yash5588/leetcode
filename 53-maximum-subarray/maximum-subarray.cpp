class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int mxm = INT_MIN;
        int sum = 0;
        int n = nums.size();
        for(int i = 0;i < n;i++) {
            sum = max(nums[i], sum + nums[i]);
            mxm = max(mxm, sum);
        }
        return mxm;
    }
};