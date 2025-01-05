class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();
        reverse(nums.begin(),nums.end());
        //non increasing we are converting to non increasing 

        //precompute the right most index element with element j
        //such that rightMostInd[i][j] stores the right most possible
        //index for that particular j element.
        //every element index remains same as that of previous index
        //only difference is previous element index need to  be updated that's it
        vector<vector<int>> rightMostInd(n, vector<int> (301,-1));
        for(int i = 1;i < n;i++) {
            for(int j = 0;j <= 300;j++) {
                rightMostInd[i][j] = rightMostInd[i-1][j];
            }
            rightMostInd[i][nums[i-1]] = i-1;
        }

        vector<vector<int>> dp(n, vector<int> (301,0));
        for(int i = 0;i < n;i++) {
            for(int diff = 0;diff <= 300;diff++) {
                int ele1 = nums[i] - diff;
                if(ele1 > 0 && rightMostInd[i][ele1] != -1) {
                    int prev_ind = rightMostInd[i][ele1];
                    // for(int preDiff = 0; preDiff <= diff; preDiff++) {
                    //     dp[i][diff] = max(dp[i][diff], dp[prev_ind][preDiff] + 1);
                    // }

                    //dp[prev_ind][diff] already stored the max uptill diff
                    dp[i][diff] = max(dp[i][diff], dp[prev_ind][diff] + 1);
                }
                int ele2 = nums[i] + diff;
                if(ele2 <= 300 && rightMostInd[i][ele2] != -1) {
                    int prev_ind = rightMostInd[i][ele2];
                    // for(int preDiff = 0; preDiff <= diff; preDiff++) {
                    //     dp[i][diff] = max(dp[i][diff], dp[prev_ind][preDiff] + 1);
                    // }
                    dp[i][diff] = max(dp[i][diff], dp[prev_ind][diff] + 1);
                }
            }
            //here dp[i][diff] stores the max uptill 0 - diff fdr a particular index i
            //to reduce time complexity
            //compute for prev Ind for later uses
            for(int diff = 1;diff <= 300;diff++) {
                dp[i][diff] = max(dp[i][diff], dp[i][diff-1]);
            }
        }
        int ma = INT_MIN;
        for(int i = 0;i < n;i++) {
            for(int diff = 0;diff <= 300;diff++) {
                ma = max(ma, dp[i][diff] + 1);
            }
        }
        return ma;
    }
};