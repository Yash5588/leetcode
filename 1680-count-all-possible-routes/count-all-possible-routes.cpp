class Solution {
public:
    int mod = 1e9+7;
    long long dp[202][202];
    long long solve(vector<int> &locations, int finish, int fuel, int prev) {
        if(fuel <= 0) return 0;
        if(dp[prev][fuel] != -1) return dp[prev][fuel];
        long long n = locations.size();
        long long count = 0;
        for(int i = 0;i < n;i++) {
            if(i != prev) {
                int consume = abs(locations[prev] - locations[i]);
                if(consume <= fuel) {
                    if(i == finish) count = (count + 1) % mod;
                }
                count = (count + solve(locations, finish, fuel-consume, i) % mod) % mod;
            }
        }
        return dp[prev][fuel] = count;
    }
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        int n = locations.size();
        long long res = 0;
        if(start == finish) res++;
        memset(dp,-1,sizeof(dp));
        res += solve(locations, finish, fuel, start);
        return res;
    }
};