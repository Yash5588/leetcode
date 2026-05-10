class Solution {
public:
    bool isPalindrome(string &s) {
        int n = s.length();
        for(int i = 0;i < n/2;i++) {
            if(s[i] != s[n-i-1]) return false;
        }
        return true;
    }
    int dp[2000];
    int solve(string &s, int idx) {
        int n = s.length();
        if(idx >= n) return 0;
        if(dp[idx] != -1) return dp[idx];
        string temp;
        int mnm = 1e5;
        for(int i = idx;i < n;i++) {
            temp += s[i];
            if(isPalindrome(temp)) {
                mnm = min(mnm, 1 + solve(s, i+1));
            }
        }
        return dp[idx] = mnm;
    }
    int minCut(string s) {
        memset(dp,-1,sizeof(dp));
        return solve(s,0)-1;
    }
};