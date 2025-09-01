class Solution {
public:
    int dp[100001][2];
    int solve(vector<int> &nums1, vector<int> &nums2, int idx, bool isSwap) {
        if(idx >= nums1.size()) return 0;
        if(dp[idx][isSwap] != -1) return dp[idx][isSwap];
        int prev1 = nums1[idx-1];
        int prev2 = nums2[idx-1];

        if(isSwap) {
            swap(prev1,prev2);
        }

        //if already strictly increasing we have two cases
        int ans = 1e9;
        if(prev1 < nums1[idx] && prev2 < nums2[idx]) {
            ans = solve(nums1, nums2, idx+1, false);
        }

        if(prev1 < nums2[idx] && prev2 < nums1[idx]) {
            ans = min(ans, 1 + solve(nums1, nums2, idx+1, true));
        }
        return dp[idx][isSwap] = ans;

    }
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        nums1.insert(nums1.begin(), -1);
        nums2.insert(nums2.begin(), -1);
        memset(dp,-1,sizeof(dp));
        return solve(nums1, nums2, 1, false);
    }
};