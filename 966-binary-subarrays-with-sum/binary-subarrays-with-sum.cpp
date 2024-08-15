class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();
        unordered_map<long long, long long> mp;
        long long sum = 0;
        long long ans = 0;
        mp[0] = 1;
        for(int i=0;i<n;i++) {
            sum += nums[i];
            ans += mp[sum-goal];
            mp[sum]++;
        }
        return ans;
    }
};