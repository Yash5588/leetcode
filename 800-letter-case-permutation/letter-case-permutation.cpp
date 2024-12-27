class Solution {
public:
    unordered_set<string> res;
    void solve(string &s, int pos) {
        int n = s.length();
        res.insert(s);
        if(pos >= n) return;
        if(s[pos] >= '0' && s[pos] <= '9') {
            solve(s, pos+1);
        }
        else {
            if(s[pos] >= 'a' && s[pos] <= 'z') {
                char temp = s[pos];
                s[pos] = (char)toupper(s[pos]);
                solve(s, pos+1);
                s[pos] = temp;
            }
            else {
                char temp = s[pos];
                s[pos] = (char)tolower(s[pos]);
                solve(s, pos+1);
                s[pos] = temp;
            }
            solve(s, pos+1);
        }
    }
    vector<string> letterCasePermutation(string s) {
        solve(s,0);
        return vector<string> (res.begin(),res.end());
    }
};