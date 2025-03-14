class Solution {
public:
    int dp[501][51][2];
    int mod = 1e9+7;
    long long solve(int n, string &s, string &evil, int pos, int matched, bool tight, vector<int> &lps) {
        // if(str.length() >= evil.length() && str.substr(str.length() - evil.length()) == evil) return 0;
        if(matched == evil.length()) return 0;
        if(pos >= n) return 1; //constructed full string
        if(dp[pos][matched][tight] != -1) return dp[pos][matched][tight];

        int cnt = 0;
        char limit = (tight) ? s[pos] : 'z';
        for(char ch = 'a'; ch <= limit; ch++) {

            int prev_index = matched;
            while(prev_index > 0 && evil[prev_index] != ch) {
                prev_index = lps[prev_index - 1];
            }

            if(evil[prev_index] == ch) prev_index++;

            cnt = (cnt + solve(n, s, evil, pos+1, prev_index, tight && (ch == s[pos]), lps) % mod) % mod;
        }

        return dp[pos][matched][tight] = cnt;
    }

    vector<int> kmp(string &str) {
        int n = str.length();
        vector<int> lps(n,0);
        for(int i = 1;i < n;i++) {
            int prev_index = lps[i-1];
            while(prev_index > 0 && str[i] != str[prev_index]) {
                prev_index = lps[prev_index - 1];
            }
            lps[i] = prev_index + (str[i] == str[prev_index]);
        }
        return lps;
    }



    int findGoodStrings(int n, string s1, string s2, string evil) {
        //build the lps for pattern
        vector<int> lps = kmp(evil);
        memset(dp, -1, sizeof(dp));
        s1.back() = s1.back()-1;
        long long left = solve(n, s1, evil, 0, 0, true, lps) % mod;
        memset(dp, -1, sizeof(dp));
        long long right = solve(n, s2, evil, 0, 0, true, lps) % mod;
        return (right - left + mod) % mod;
    }
};