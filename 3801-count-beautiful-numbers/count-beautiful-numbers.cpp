class Solution {
public:
    unordered_map<string,int> dp;
    int solve(string &s, int idx, bool tight, bool isLeading, int sum, int prod) {
        int n = s.length();
        if(idx >= n) {
            if(sum == 0) return 0;
            return (prod % sum == 0) ? 1 : 0;
        }
        string key = to_string(idx) + '#' + to_string(tight) + '#' + to_string(isLeading) + '#' + to_string(sum) + '#' + to_string(prod);
        if(dp.find(key) != dp.end()) return dp[key];
        int limit = (tight) ? s[idx] - '0' : 9;
        int cnt = 0;
        for(int d = 0;d <= limit;d++) {
            cnt += solve(s, idx+1, tight && (d == s[idx]-'0'), isLeading && (d == 0), sum + d, (isLeading) ? (d>0 ? d : 1) : prod * d);
        }
        return dp[key] = cnt;
    }
    int beautifulNumbers(int l, int r) {
        string str_l = to_string(l-1);
        string str_r = to_string(r);
        int left = solve(str_l, 0, 1, 1, 0, 1);
        dp.clear();
        int right = solve(str_r, 0, 1, 1, 0, 1);
        return right - left;
    }
};