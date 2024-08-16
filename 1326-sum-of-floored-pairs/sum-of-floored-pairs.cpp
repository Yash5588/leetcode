class Solution {
public:
    int MOD = 1e9+7;
    long long N = 100000;
    int sumOfFlooredPairs(vector<int>& nums) {
        vector<long long> count(N+1,0);
        unordered_set<long long> se;
        for(auto &x : nums) {
            count[x]++;
            se.insert(x);
        }
        for(int i=1;i<=N;i++) {
            count[i] += count[i-1];
        }
        long long ans = 0;
        for(auto &i : se) {
            long long val = 0;
            for(int j = 1; i*j <= N; j++) {
                long long left = i*j;
                long long right = i*(j+1) - 1;
                right = min(right,N);
                long long cnt = count[right] - count[left-1];
                val = (val + (cnt*j) % MOD) % MOD;
            }
            long long c = count[i] - count[i-1];
            ans = (ans + (val*c) % MOD) % MOD;
        }
        return ans;
    }
};