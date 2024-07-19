class Solution {
public:
    int MOD = 1e9+7;
    int countMatchingSubarrays(vector<int>& nums, vector<int>& p) {
        int n = nums.size();
        int m = p.size();
        long long phash = 0, hash = 0;
        long long radix = 1;
        for(int i=0;i<n-1;i++) {
            if(nums[i] < nums[i+1]) {
                nums[i] = 1;
            }
            else if(nums[i] == nums[i+1]) {
                nums[i] = 0;
            }
            else {
                nums[i] = 2;
            }
        }
        nums.resize(n-1);
        for(int i=0;i<m;i++) {
            if(p[m-i-1] == -1) p[m-i-1] = 2;
            phash = ((phash + (p[m-i-1]*radix) % MOD) + MOD) % MOD;
            hash = ((hash + (nums[m-i-1]*radix) % MOD) + MOD) % MOD;
            radix = (radix * 3) % MOD;
        }
        long long count = 0;
        count += (hash == phash);
        for(int i=0;i<n-m;i++) {
            hash = (hash * 3) % MOD;
            hash = ((hash - (nums[i]*radix) % MOD) + MOD) % MOD;
            hash = (hash + nums[i+m]) % MOD;
            count += (hash == phash);
        }
        return count;
    }
};