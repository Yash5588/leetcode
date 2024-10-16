class Solution {
public:
    long long appealSum(string s) {
        int n = s.length();
        unordered_map<char,int> mp;
        vector<long long> dp(n);
        dp[0] = 1;
        mp[s[0]] = 1;
        for(int i = 1;i < n;i++) {
            dp[i] = (dp[i-1] + i + 1) - mp[s[i]];
            mp[s[i]] = i+1;
        }
        long long res= 0;
        for(auto &x : dp) res += x;
        return res;
    }
};