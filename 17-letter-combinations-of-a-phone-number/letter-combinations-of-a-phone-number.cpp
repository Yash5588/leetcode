class Solution {
public:
    vector<string> digit_str;
    vector<string> res;
    void backTrack(string str,string &digits, int pos) {
        int n = digits.length();
        if(pos >= n) {
            res.push_back(str);
            return;
        }
        string s = digit_str[digits[pos]-'0'];
        for(auto &ch : s) {
            str += ch;
            backTrack(str,digits,pos+1);
            str.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        digit_str.resize(10);
        if(digits.empty()) return {};
        digit_str[2] = "abc";
        digit_str[3] = "def";
        digit_str[4] = "ghi";
        digit_str[5] = "jkl";
        digit_str[6] = "mno";
        digit_str[7] = "pqrs";
        digit_str[8] = "tuv";
        digit_str[9] = "wxyz";
        backTrack("",digits,0);
        return res;
    }
};