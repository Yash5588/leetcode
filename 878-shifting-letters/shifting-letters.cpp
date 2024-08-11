class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        int n = s.length();
        vector<int> suffix(n+1,0);
        for(int i=n-1;i>=0;i--) {
            suffix[i] = suffix[i+1] + shifts[i];
            suffix[i] %= 26;
        }
        string ans;
        for(int i=0;i<n;i++) {
            ans += char((((int(s[i]) + suffix[i]) % 97) % 26) + 97);
        }
        return ans;

    }
};