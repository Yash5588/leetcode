class Solution {
public:
    int dp[1001][1001];
    bool subsequenceSum(vector<int> &valids, int target, int pos) {
        if(target < 0) return false;
        if(pos >= valids.size()) {
            if(target == 0) return true;
            return false;
        }
        if(dp[target][pos] != -1) return dp[target][pos];
        return dp[target][pos] = subsequenceSum(valids, target, pos+1) | subsequenceSum(valids, target - valids[pos], pos+1);
    }
    bool isPossible(vector<int> &nums, vector<vector<int>> &queries, int k) {
        int n = nums.size();
        for(int i = 0;i < n;i++) {
            vector<int> valids; //stores all the vals in queries which can be applied to this nums[i]
            //l <= i <= r;
            for(int j = 0;j < k;j++) {
                int l = queries[j][0];
                int r = queries[j][1];
                int val = queries[j][2];
                if(l <= i && i <= r) valids.push_back(val);
            }
            //now our problem boils down to find a subsequence in valids such that it's sum becomes equal to nums[i]
            //it means that it can be made equal to 0
            memset(dp, -1, sizeof(dp));
            bool canMake = subsequenceSum(valids, nums[i], 0);
            if(!canMake) return false;
        }
        return true;
    }
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int low = 0, high = queries.size();
        int ans = -1;
        while(low <= high) {
            int mid = low + (high - low)/2;
            if(isPossible(nums, queries, mid)) {
                ans = mid;
                high = mid - 1;
            }
            else low = mid + 1;
        }
        return ans;
    }
};