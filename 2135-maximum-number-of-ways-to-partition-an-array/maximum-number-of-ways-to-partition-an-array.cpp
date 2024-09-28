class Solution {
public:
    int waysToPartition(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> prefix(n,0);
        vector<long long> suffix(n,0);
        prefix[0] = nums[0];
        suffix[n-1] = nums[n-1];
        for(int i = 1;i < n;i++) {
            prefix[i] = prefix[i - 1] + nums[i];
        }
        for(int i = n-2;i >= 0;i--) {
            suffix[i] = suffix[i + 1] + nums[i];
        }
        unordered_map<long long,long long> right,left;
        for(int i = 0;i < n - 1;i++) {
            right[prefix[i] - suffix[i+1]]++;
        }
        long long ans = right[0];
        for(int i = 0;i < n;i++) {
            long long diff = k - nums[i];
            long long cnt = 0;
            cnt = left[diff] + right[-diff];
            ans = max(ans,cnt);
            if(i < n-1) {
                int d = prefix[i] - suffix[i+1];
                left[d]++;
                right[d]--;
                if(right[d] == 0) right.erase(d);
            }
        }
        return ans;
    }
};