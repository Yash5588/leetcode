class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+1,1);
        vector<int> cnt(n+1,1);
        int mxm = 1;
        for(int i = 1;i <= n;i++) {
            for(int j = 1;j < i;j++) {
                if(nums[i-1] > nums[j-1]) {
                    if(dp[i] < dp[j] + 1) {
                        dp[i] = dp[j]+1;
                        cnt[i] = cnt[j];
                    }
                    else if(dp[i] == dp[j] + 1) {
                        cnt[i] += cnt[j];
                    }
                    mxm = max(mxm, dp[i]);
                }
            }
        }
        int c = 0;
        cout << mxm << endl;
        for(int i = 1;i <= n;i++) {
            if(dp[i] == mxm) {
                c += cnt[i];
            }
        }
        return c;
    }
};