class Solution {
public:
    int dp[20][20];
    bool solve(string &s, string &p,  int i, int j) {
        int n1 = s.length();
        int n2 = p.length();

        if(i >= n1 && j >= n2) return true;
        if(j >= n2) return false; 
        if(i < n1 && (s[i] == p[j] || p[j] == '.')) {
            if(j+1 < n2 && p[j+1] == '*') {
                return solve(s,p,i+1,j) || solve(s,p,i,j+2);
            }
            return solve(s,p,i+1,j+1);
        }
        if(j+1 < n2 && p[j+1] == '*') {
            return solve(s,p,i,j+2);
        }
        return false;
    }
    bool isMatch(string s, string p) {
        memset(dp,-1,sizeof(dp));
        return solve(s, p, 0, 0);
    }
};