class Solution {
public:
    int mod = 1e9+7;
    // map<string,int> dp;
    long long dp[1000][2002][3];
    long long solve(string &s, int pos, char prev, long long score) {
        int n = s.length();
        if(pos >= n) {
            return score > 0;
        }
        // string key = to_string(pos) + to_string(score) + prev;
        // if(dp.find(key) != dp.end()) return dp[key];
        int val;
        if(prev == 'F') val = 0; 
        else if(prev == 'W') val = 1; 
        else val = 2; 
        if(dp[pos][score+1000][val] != -1) return dp[pos][score+1000][val];
        long long ans = 0;
        if(s[pos] == 'F') {
            if(prev == 'F') ans = (ans + solve(s,pos+1,'W',score+1)%mod + solve(s,pos+1,'E',score-1)%mod)%mod;
            else if(prev == 'W') ans = (ans + solve(s,pos+1,'F',score)%mod + solve(s,pos+1,'E',score-1)%mod)%mod;
            else ans = (ans + solve(s,pos+1,'F',score)%mod + solve(s,pos+1,'W',score+1)%mod)%mod;
        }
        else if(s[pos] == 'W') {
            if(prev == 'F') ans = (ans + solve(s,pos+1,'W',score)%mod + solve(s,pos+1,'E',score+1)%mod)%mod;
            else if(prev == 'W') ans = (ans + solve(s,pos+1,'F',score-1)%mod + solve(s,pos+1,'E',score+1)%mod)%mod;
            else ans = (ans + solve(s,pos+1,'F',score-1)%mod + solve(s,pos+1,'W',score)%mod)%mod;
        }
        else {
            if(prev == 'F') ans = (ans + solve(s,pos+1,'W',score-1)%mod + solve(s,pos+1,'E',score)%mod)%mod;
            else if(prev == 'W') ans = (ans + solve(s,pos+1,'F',score+1)%mod + solve(s,pos+1,'E',score)%mod)%mod;
            else ans = (ans + solve(s,pos+1,'F',score+1)%mod + solve(s,pos+1,'W',score-1)%mod)%mod;
        }
        return dp[pos][score+1000][val] = ans;
    }
    int countWinningSequences(string s) {
        long long ans = 0;
        memset(dp,-1,sizeof(dp));
        if(s[0] == 'F') {
            ans = (ans + solve(s,1,'F',0)%mod + solve(s,1,'W',1)%mod + solve(s,1,'E',-1)%mod)%mod;
        }
        if(s[0] == 'W') {
            ans = (ans + solve(s,1,'F',-1)%mod + solve(s,1,'W',0)%mod + solve(s,1,'E',1)%mod)%mod;
        }
        if(s[0] == 'E') {
            ans = (ans + solve(s,1,'F',1)%mod + solve(s,1,'W',-1)%mod + solve(s,1,'E',0)%mod)%mod;
        }
        return ans%mod;
    }
};