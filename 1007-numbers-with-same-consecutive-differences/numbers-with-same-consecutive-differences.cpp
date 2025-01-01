class Solution {
public:
    unordered_set<int> res;
    void solve(int n, int k, string &s, int prev, int pos) {
        if(pos >= n) {
            res.insert(stoll(s));
            return;
        }

        if(prev + k < 10 && res.find(prev+k) == res.end()) {
            s += to_string(prev + k);
            solve(n, k, s, prev+k, pos+1);
            s.pop_back();
        } 
        if(prev - k >= 0 && res.find(prev-k) == res.end()) {
            s += to_string(prev - k);
            solve(n, k, s,prev-k, pos+1);
            s.pop_back();
        }
    }
    vector<int> numsSameConsecDiff(int n, int k) {
        string s;
        for(int i = 1;i <= 9;i++) {
            s += to_string(i);
            solve(n, k, s, i, 1);
            s.pop_back();
        }
        return vector<int> (res.begin(),res.end());
    }
};