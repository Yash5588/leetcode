class Solution {
public:
    vector<int> kmp(string &s, string rev) {
        string str = s + '#' + rev;
        vector<int> lps(str.length(),0);
        for(int i=1;i<str.length();i++) {
            int prev_index = lps[i-1];
            while(prev_index>0 && str[prev_index] != str[i]) {
                prev_index = lps[prev_index-1];
            }
            lps[i] = prev_index + (str[prev_index] == str[i]);
        }
        return lps;
    }
    string shortestPalindrome(string s) {
        int n = s.length();
        string rev = s;
        reverse(rev.begin(),rev.end());
        vector<int> lps = kmp(s,rev);
        int len = lps[2*n];
        return rev.substr(0,n-len) + s;
    }
};