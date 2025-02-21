class Solution {
public:
    // string dp[12][1 << 12];
    vector<int> kmp(string &s, string &pattern) {
        string str = pattern + '#' + s;
        int n = str.length();
        vector<int> lps(n,0);
        for(int i = 1;i < n;i++) {
            int prev_index = lps[i-1];
            while(prev_index > 0 && str[i] != str[prev_index]) {
                prev_index = lps[prev_index-1];
            }
            lps[i] = prev_index + (str[i] == str[prev_index]);
        }
        return lps;
    }

    string solve(int prev_idx, int mask, vector<vector<string>> &suffix, vector<vector<string>> &dp) {
        int n = suffix.size();
        if(mask == (1 << n)-1) {
            return "";
        }
        if(dp[prev_idx][mask] != "#") return dp[prev_idx][mask];

        string res;
        int res_len = 1e9;
        for(int i = 0;i < n;i++) {
            if(mask & (1 << i)) continue;
            string temp = suffix[prev_idx][i] + solve(i, mask | (1 << i), suffix, dp);
            if(res_len > temp.size()) {
                res = temp;
                res_len = temp.size();
            }
        }
        return dp[prev_idx][mask] = res;
    }
    string shortestSuperstring(vector<string>& words) {
        int n = words.size();
        vector<vector<string>> suffix(n, vector<string> (n,""));

        //suffix[i][j] stores the non equal suffix part of i and j
        //ex: words[i] = gcta and words[j] = "ctaatg"
        //then suffix[i][j] stores "atg" becoz "cta" is overlapping part
        //also "atg" from second word
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < n;j++) {
                vector<int> lps = kmp(words[i], words[j]);
                int suffix_match = lps.back();
                suffix[i][j] = words[j].substr(suffix_match);
            }
        }

        string res;
        int res_len = 1e9;

        // memset(dp,"#",sizeof(dp));
        vector<vector<string>> dp(n, vector<string>(1 << n, "#"));
        for(int i = 0;i < n;i++) {
            string temp = words[i] + solve(i, 1 << i, suffix, dp);
            if(res_len > temp.size()) {
                res = temp;
                res_len = temp.size();
            }
        }
        return res;
    }
};