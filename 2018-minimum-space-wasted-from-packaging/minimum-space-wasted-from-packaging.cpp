class Solution {
public:
    int mod = 1e9+7;
    int minWastedSpace(vector<int>& nums, vector<vector<int>>& boxes) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        long long mi = LONG_MAX;
        long long sum = 0;
        for(auto &x : nums) {
            sum += x;
        }
        for(auto &box : boxes) {
            long long curr = 0,prev = 0;
            sort(box.begin(),box.end());
            long long capacity = 0;
            if(nums.back() > box.back()) continue;
            for(auto &x : box) {
                curr = upper_bound(nums.begin(),nums.end(),x) - nums.begin();
                capacity += (curr - prev) * x;
                prev = curr;
            }
            mi = min(mi, capacity);
        }
        return (mi == LONG_MAX) ? -1 : (mi%mod - sum%mod)%mod;
    }
};