class Solution {
public:
    int longestSubstring(string s, int k) {
        if(s.empty()) return 0;
        vector<int> freq(26,0);
        for(auto &x : s) {
            freq[x-'a']++;
        }
        int n = s.length();
        for(int i = 0;i < n;i++) {
            if(freq[s[i]-'a'] < k) {
                int left = longestSubstring(s.substr(0,i),k);
                int right = longestSubstring(s.substr(i+1,n),k);
                return max(left,right);
            }
        }
        return s.length();
    }
};