class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> prefix(n,0);
        prefix[0] = nums[0];
        for(int i = 1;i < n;i++) {
            prefix[i] = prefix[i-1] + nums[i];
        }
        unordered_map<long long,long long> mp;
        for(int i = 0;i < k-1;i++) {
            mp[i] = prefix[i];
        }
        //becoz it is also a subarray divisible by k
        long long ma = prefix[k-1];
        for(int i = k-1;i < n;i++) {
            //we have to minimize mp[i%k] so that sum will be maximized
            long long sum = prefix[i] - mp[i%k];
            ma = max(ma, sum);
            mp[i%k] = min(mp[i%k], prefix[i]);
        }
        return ma;
    }
};