class Solution {
public:
    //top down approach O(n^2)
    // unordered_map<string,int> dp;
    // long long solve(vector<int> &nums, int k, int prev, int pos, int flag) {
    //     long long n = nums.size();
    //     if(pos >= n) {
    //         if(flag == 0) return INT_MIN;
    //         return 0;
    //     }
    //     string key = to_string(prev) + '#' + to_string(pos) + to_string(flag);
    //     if(dp.find(key) != dp.end()) return dp[key];
    //     long long pick = INT_MIN,not_pick = INT_MIN;
    //     if(prev == -1 || pos - prev <= k) {
    //         pick = nums[pos] + solve(nums,k,pos,pos+1,1);
    //     }
    //     not_pick = solve(nums,k,prev,pos+1,flag);
    //     return dp[key] = max(pick,not_pick);
    // }
    int constrainedSubsetSum(vector<int>& nums, int k) {
        //bottom up approach
        int n = nums.size();
        multiset<int,greater<int>> se;
        vector<int> dp(n,0);
        int ma = nums[0];
        se.insert(nums[0]);
        dp[0] = nums[0];
        for(int i = 1;i < n;i++) {
            //no need to remove if sliding window size is less than k
            //window exceeds then remove those elements beyond window size
            if(i > k) {
                se.erase(se.find(dp[i-k-1]));
            }
            dp[i] = max(nums[i], nums[i] + *se.begin());
            ma = max(ma, dp[i]);
            se.insert(dp[i]);
        }
        // for(int i = 0;i < n;i++) cout << dp[i] << ' ';
        return ma;
    }
};