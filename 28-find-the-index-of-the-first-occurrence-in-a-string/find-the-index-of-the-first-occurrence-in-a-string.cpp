class Solution {
public:
    vector<int> kmp(string &s, string &pattern) {
        string str = pattern + '#' + s;
        vector<int> lps(str.size(),0);
        for(int i=1;i<str.size();i++) {
            int prev_index = lps[i-1];
            while(prev_index>0 && str[prev_index] != str[i]) {
                prev_index = lps[prev_index-1];
            }
            lps[i] = prev_index + (str[prev_index] == str[i]);
        }
        return lps;
    }
    int strStr(string s, string pattern) {
        int n = s.length();
        int m = pattern.size();
        vector<int> lps = kmp(s,pattern);
        for(int i=0;i<lps.size();i++) {
            if(lps[i] == m) return i-2*m;
        }
        return -1; 
    }
};