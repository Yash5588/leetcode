class Solution {
public:
    long long dp[1000][1000];
    int mod = 1e9+7;
    long long powMod(int x, int n, int M) {
        
        // Initialize result as 1 (since anything power 0 is 1)
        long long res = 1;

        // n times to multiply x with itself
        for(int i = 1; i <= n; i++) {
                    
            // Multiplying res with x 
            // and taking modulo to avoid overflow
            res = (res * x) % M;
        }

        return res;
    }

    long long solve(vector<int> &nums, int k, int idx, long long sum) {
        if(sum >= k) return 0;
        if(idx >= nums.size()) {
            return 1;
        }
        if(dp[idx][sum] != -1) return dp[idx][sum];
        return dp[idx][sum] = (solve(nums,k,idx+1,sum)%mod + solve(nums, k, idx+1, sum + (long long)nums[idx])%mod)%mod;

    }
    int countPartitions(vector<int>& nums, int k) {
        int n = nums.size();
        if(accumulate(nums.begin(),nums.end(),0LL) < 2*k) return 0;
        memset(dp,-1,sizeof(dp));
        return (powMod(2,n,mod) - ((2*solve(nums,k,0,0) % mod)) + mod)%mod; 
    }
};