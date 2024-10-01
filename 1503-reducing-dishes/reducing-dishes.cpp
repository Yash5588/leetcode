class Solution {
public:
    int dp[502][502];
    int solve(vector<int> &nums, int pos, int val) {
        int n = nums.size();
        if(pos >= n) return 0;
        if(dp[pos][val] != -1) return dp[pos][val];
        int pick = nums[pos]*val + solve(nums,pos+1,val+1);
        int not_pick = solve(nums,pos+1,val);
        return dp[pos][val] = max(pick, not_pick);
    }
    int maxSatisfaction(vector<int>& satisfaction) {
        int n = satisfaction.size();
        sort(satisfaction.begin(),satisfaction.end());
        memset(dp,-1,sizeof(dp));
        return solve(satisfaction,0,1);
    }
};