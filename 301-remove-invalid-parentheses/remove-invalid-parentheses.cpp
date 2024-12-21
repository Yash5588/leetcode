class Solution {
public:
    //to store unique permutations
    unordered_set<string> res;
    int ma = 0;
    void backtrack(string &s, int pos, int left, int right, string &temp) {
        int n = s.length();
        if(pos >= n) {
            if(left == right) {
                //if a new string which has max length then previous are less than this
                //so remove all of them and update max
                if(temp.length() > ma) {
                    res.clear();
                    ma = temp.length();
                }
                //if my current string has length equal to max then store it
                if(temp.length() == ma) res.insert(temp);
            }
            return;
        }
        if(s[pos] == '(') {
            temp += '(';
            backtrack(s, pos+1, left + 1, right , temp);
            temp.pop_back();
            backtrack(s, pos+1, left, right, temp);
        }
        else if(s[pos] == ')') {
            //right braces should always be <= left braces
            if(left > right) {
                temp += ')';
                backtrack(s, pos+1, left, right + 1, temp);
                temp.pop_back();
            }
            backtrack(s, pos+1, left, right, temp);
        }
        else {
            temp += s[pos];
            backtrack(s, pos+1, left, right, temp);
            temp.pop_back();
        }
    }
    vector<string> removeInvalidParentheses(string s) {
        string temp;
        backtrack(s, 0, 0, 0, temp);
        return vector<string> (res.begin(),res.end());
    }
};