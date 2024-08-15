class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();
        //for maintaining the count for prefix sum;
        unordered_map<long long, long long> mp;
        long long sum = 0;
        long long ans = 0;
        mp[0] = 1;
        for(int i=0;i<n;i++) {
            //prefix sum
            sum += nums[i];

            //getting the sum-goal count
            ans += mp[sum-goal];

            //updating current sum count
            mp[sum]++;
        }
        return ans;
    }
};