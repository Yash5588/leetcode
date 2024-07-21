class Solution {
public:
    vector<int> kmp(string &s) {
        int n = s.length();
        vector<int> lps(n,0);
        for(int i=1;i<n;i++) {
            int prev_index = lps[i-1];
            while(prev_index>0 && s[prev_index] != s[i]) {
                prev_index = lps[prev_index-1];
            }
            lps[i] = prev_index + (s[prev_index] == s[i]);
        }
        return lps;
    }
    string longestPrefix(string s) {
        vector<int> lps = kmp(s);
        return s.substr(0,lps[s.length()-1]);
    }
};