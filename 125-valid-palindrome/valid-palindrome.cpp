class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.length();
        int first = 0,last = n-1;
        while(first < last) {
            while(first < last && !isalnum(s[first])) first++;
            while(first < last && !isalnum(s[last])) last--;
            if(first < last) {
                if((char)tolower(s[first]) == (char)tolower(s[last])) {
                    first++;
                    last--;
                }
                else break;
            }
        }
        return first >= last;
    }
};