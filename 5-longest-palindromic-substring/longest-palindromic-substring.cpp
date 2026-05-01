class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        int idx = 0, maxLen = 0;
        for(int i = 0;i < n;i++) {
            int left = i, right = i;
            while(left >= 0 && right < n && s[left] == s[right]) {
                left--;
                right++;
            }
            int start = left + 1;
            int end = right - 1;
            int len = end - start + 1;
            if(maxLen < len) {
                maxLen = len;
                idx = start;
            }

            left = i, right = i+1;
            while(left >= 0 && right < n && s[left] == s[right]) {
                left--;
                right++;
            }
            start = left + 1;
            end = right - 1;
            len = end - start + 1;
            if(maxLen < len) {
                maxLen = len;
                idx = start;
            }
        }
        return s.substr(idx, maxLen);
    }
};