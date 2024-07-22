class Solution {
public:
    vector<int> kmp(string &s, string &b) {
        string str = b + '#' + s;
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
    int repeatedStringMatch(string a, string b) {
        if(a == b) return 1;
        string str = a;
        int n = a.length(),m = b.length();
        for(int i=0;i<=m/n;i++) {
            str += a;
        }
        vector<int> lps = kmp(str,b);
        for(int i=0;i<lps.size();i++) {
            if(lps[i] == m) {
                int ind = i-m;
                if(ind%n) return ind/n+1;
                return ind/n;
            }
        }
        return -1;
    }
};