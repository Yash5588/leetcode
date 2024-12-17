class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,1);
        vector<int> count(n,1);
        int ma = INT_MIN;
        for(int i = 0;i < n;i++) {
            for(int prev = 0;prev < i;prev++) {
                if(nums[i] > nums[prev]) {
                    //newly formed LIS length now for it the count is same as prev lis
                    if(dp[i] < dp[prev] + 1) {
                        dp[i] = dp[prev] + 1;
                        count[i] = count[prev];
                    }
                    //if max is seen again visualize it we found more of same max len lis so add those freq as well
                    else if(dp[i] == dp[prev] + 1) {
                        count[i] += count[prev];
                    }
                }
            }
            ma = max(ma, dp[i]);
        }
        //get max length lis count 
        int total_count = 0;
        for(int i = 0;i < n;i++) {
            if(dp[i] == ma) {
                total_count += count[i];
            }
        }
        return total_count;
    }
};