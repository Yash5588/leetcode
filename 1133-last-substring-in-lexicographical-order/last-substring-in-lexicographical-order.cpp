class Solution {
public:
    string lastSubstring(string s) {
        int n = s.length();
        int i=0,j = 1,offset = 0;
        while(j + offset < n) {
            if(s[i + offset] == s[j + offset]) {
                offset++;
            }
            else if(s[i + offset] < s[j + offset]) {
                i = max(i + offset + 1, j);
                j = i + 1;
                offset = 0;
            }
            else {
                j = j + offset + 1;
                offset = 0;
            }
        }
        return s.substr(i,n);
    }
};