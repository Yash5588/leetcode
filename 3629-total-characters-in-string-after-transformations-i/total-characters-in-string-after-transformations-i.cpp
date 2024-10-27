class Solution {
public:
    int mod = 1e9+7;
    unordered_map<string,long long> dp;
    int solve(string s,int t) {
        long long ans = 0;
        string key = s + to_string(t);
        if(dp.find(key) != dp.end()) return dp[key];
        for(auto &ch : s) {
            if((ch - 'a') + t < 26) ans++;
            else ans = (ans + solve("ab",t - (26 - (ch-'a')))%mod)%mod;
        }
        return dp[key] = ans%mod;
    }
    int lengthAfterTransformations(string s, int t) {
        return solve(s,t)%mod;
    }
};
