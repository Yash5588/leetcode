class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        map<long long,long long> mp;
        long long sum = 0;
        long long mi = INT_MAX;
        mp[0] = -1;
        for(int i=0;i<n;i++) {
            sum += nums[i];
            while(mp.begin()->first <= sum-k && mp.begin() != mp.end()) {
                mi = min(mi, i - mp.begin()->second);
                mp.erase(mp.begin());
            }
            mp[sum] = i;
        }
        if(mi == INT_MAX) return -1;
        return mi;
    }
};