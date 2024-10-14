class Solution {
public:
    unordered_map<string,bool> dp;
    bool solve(vector<int> &s, int pos, int prev) {
        int n = s.size();
        if(pos == n-1) return true;
        // if(pos >= n) return false;
        string key = to_string(pos) + '#' + to_string(prev);
        if(dp.find(key) != dp.end()) return dp[key];
        for(int i = pos+1;i < n;i++) {
            if(s[i] - s[pos] >= prev-1 && s[i] - s[pos] <= prev+1) {
                if(solve(s, i, s[i] - s[pos])) return dp[key] = true;
            }
        }
        return dp[key] = false;
    }
    bool canCross(vector<int>& s) {
        int n = s.size();
        if(s[1] - s[0] == 1) {
            return solve(s,1,1);
        }
        return false;
    }
};