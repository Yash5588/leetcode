class Solution {
public:
    long long dp[1000];
    long long split(string &s, unordered_set<string> &words, int pos) {
        if(pos >= s.length()) return 0;
        if(dp[pos] != -1) return dp[pos];
        long long mi = INT_MAX;
        string str;
        int total = 0;
        for(int i=pos;i<s.length();i++) {
            str += s[i];
            if(!words.count(str)) {
                total++;
            }
            else total=0;
            mi = min(mi, total + split(s,words,i+1));
        }
        return dp[pos] = mi;
    }
    int minExtraChar(string s, vector<string>& dict) {
        unordered_set<string> words(dict.begin(),dict.end());
        memset(dp,-1,sizeof(dp));
        return split(s,words,0);
    }
};