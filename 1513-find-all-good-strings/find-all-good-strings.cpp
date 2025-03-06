class Solution {
public:
    int dp[501][51][2][2];
    int mod = 1e9+7;
    int solve(int n, string &s1, string &s2, string &evil, int pos, int matched, bool leftBound, bool rightBound, vector<int> &lps) {
        // if(str.length() >= evil.length() && str.substr(str.length() - evil.length()) == evil) return 0;
        if(matched == evil.length()) return 0;
        if(pos >= n) return 1; //constructed full string
        if(dp[pos][matched][leftBound][rightBound] != -1) return dp[pos][matched][leftBound][rightBound];
        char from = leftBound ? s1[pos] : 'a';
        char to = rightBound ? s2[pos] : 'z';
        int cnt = 0;
        for(char ch = from; ch <= to; ch++) {

            int prev_index = matched;
            while(prev_index > 0 && evil[prev_index] != ch) {
                prev_index = lps[prev_index - 1];
            }

            if(evil[prev_index] == ch) prev_index++;

            cnt = (cnt + solve(n, s1, s2, evil, pos+1, prev_index, leftBound && (ch == from), rightBound && (ch == to), lps) % mod) % mod;
        }

        return dp[pos][matched][leftBound][rightBound] = cnt;
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
        memset(dp, -1, sizeof(dp));
        //build the lps for pattern
        vector<int> lps = kmp(evil);
        return solve(n, s1, s2, evil, 0, 0, true, true, lps) % mod;
    }
};