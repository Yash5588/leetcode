class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        int n = s.length();
        vector<long long> suffix(n+1,0);
        for(int i=n-1;i>=0;i--) {
            suffix[i] = suffix[i+1] + shifts[i];
        }
        string ans;
        for(int i=0;i<n;i++) {
            ans += (((s[i]-'a') +suffix[i]) % 26) + 'a';
        }
        return ans;

    }
};