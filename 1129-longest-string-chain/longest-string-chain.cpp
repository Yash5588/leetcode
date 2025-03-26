class Solution {
public:
    unordered_set<string> se;
    unordered_map<string,int> dp;
    int solve(string word) {
        int n = word.length();
        int ma = 0;
        if(dp.find(word) != dp.end()) return dp[word];
        for(int i = 0;i < n;i++) {
            string prefix = word.substr(0,i);
            string suffix = word.substr(i+1,n-i-1);
            string str = prefix + suffix;
            if(se.find(str) != se.end()) {
                ma = max(ma, 1 + solve(str));
            }
        }
        return dp[word] = ma;
    }
    int longestStrChain(vector<string>& words) {
        for(auto &x : words) se.insert(x);
        int ma = INT_MIN;
        unordered_set<string> se;
        for(auto &word : words) {
            ma = max(ma, solve(word));
        }
        return ma+1;
    }
};