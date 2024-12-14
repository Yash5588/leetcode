class Solution {
public:
    vector<string> res;
    void solve(string &num, int target, int pos, string s, long long result, long long prev) {
        int n = num.length();
        if(pos >= n) {
            if(result == target) {
                res.push_back(s);
            }
            return;
        }
        string str;
        for(int i = pos;i < n;i++) {
            if(i > pos && num[pos] == '0') return;
            //avoid leading zero's but consider single 0 case
            str += num[i];
            long long currVal = stoll(str);
            solve(num, target, i+1, s + '+' + str, result + currVal, currVal);
            solve(num, target, i+1, s + '-' + str, result - currVal, -currVal);
            solve(num, target, i+1, s + '*' + str, result - prev + (prev * currVal), prev * currVal);
        }
    }
    vector<string> addOperators(string num, int target) {
        int n = num.length();
        string str;
        for(int i = 0;i < n;i++) {
            //leading zero cases all remove but consider single zero which is starting one
            if(i > 0 && num[0] == '0') break;
            str += num[i];
            long long currVal = stoll(str);
            solve(num, target, i+1, str, currVal, currVal);
        }
        return res;
    }
};