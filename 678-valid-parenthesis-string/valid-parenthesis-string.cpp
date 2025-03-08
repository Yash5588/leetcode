class Solution {
public:
    int dp[100][100][100];
    bool solve(string &s, int left, int right, int pos) {
        int n = s.length();
        if(pos >= n) {
            return left == right;
        }
        if(dp[left][right][pos] != -1) return dp[left][right][pos];
        if(right > left) {
            return false;
        }
        bool flag = false;
        if(s[pos] == '(') {
            flag |= solve(s, left+1, right, pos+1);
        }
        else if(s[pos] == ')') {
            flag |= solve(s, left, right+1, pos+1);
        }
        else {
            flag |= solve(s, left+1, right, pos+1);
            flag |= solve(s, left, right+1, pos+1);
            flag |= solve(s, left, right, pos+1);
        }
        return dp[left][right][pos] = flag;
    }
    bool checkValidString(string s) {
        memset(dp,-1,sizeof(dp));
        return solve(s, 0, 0, 0);
    }
};