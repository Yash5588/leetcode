class Solution {
public:
    vector<string> letterCasePermutation(string s) {
        //get all possible bit combinations
        int n = s.length();
        unordered_set<string> res;
        res.insert(s);
        for(int i = 0;i <= pow(2,n);i++) {
            string t = s;
            for(int j = 0;j < n;j++) {
                if(i & (1 << j)) {
                    if(s[j] >= '0' && s[j] <= '9') continue;
                    if(s[j] >= 'a' && s[j] <= 'z') {
                        char temp = s[j];
                        s[j] = (char)toupper(s[j]);
                        res.insert(s);
                    }
                    else {
                        char temp = s[j];
                        s[j] = (char)tolower(s[j]);
                        res.insert(s);
                    }
                }
            }
            s = t;
        }
        return vector<string> (res.begin(),res.end());
    }
};