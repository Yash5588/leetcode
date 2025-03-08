class Solution {
public:
    int dp[100][100];
    //+1 for left and -1 for right
    bool solve(string &s, int bracket, int pos) {
        int n = s.length();
        if(pos >= n) {
            return bracket == 0;
        }
        if(bracket < 0) {
            return false;
        }
        if(dp[pos][bracket] != -1) return dp[pos][bracket];
        bool flag = false;
        if(s[pos] == '(') {
            flag |= solve(s, bracket+1, pos+1);
        }
        else if(s[pos] == ')') {
            flag |= solve(s, bracket-1, pos+1);
        }
        else {
            flag |= solve(s, bracket+1, pos+1);
            flag |= solve(s, bracket-1, pos+1);
            flag |= solve(s, bracket, pos+1);
        }
        return dp[pos][bracket] = flag;
    }
    bool checkValidString(string s) {
        memset(dp,-1,sizeof(dp));
        return solve(s, 0, 0);
    }
};