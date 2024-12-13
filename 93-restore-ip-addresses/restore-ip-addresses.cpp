class Solution {
public:
    vector<string> res;
    void solve(string &s, int level, int pos, string ip) {
        int n = s.length();
        if(level >= 4) {
            if(pos >= n) {
                ip.pop_back(); //remove last dot
                res.push_back(ip);
            }
            return;
        }
        if(pos >= n) return;
        if(s[pos] == '0') {
            solve(s,level+1,pos+1,ip + "0.");
        }
        else {
            solve(s,level+1,pos+1,ip + s[pos] + '.');
            if(pos+1 < n) {
                solve(s,level+1,pos+2,ip + s.substr(pos,2) + '.');
            }
            if(pos+2 < n) {
                string t = s.substr(pos,3);
                if(stoi(t) <= 255) {
                    solve(s,level+1,pos+3,ip + s.substr(pos,3) + '.');
                }
            }
        }
    }
    vector<string> restoreIpAddresses(string s) {
        int n = s.length();
        solve(s,0,0,"");
        return res;
    }
};