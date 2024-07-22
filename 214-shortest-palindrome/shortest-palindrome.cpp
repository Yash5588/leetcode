class Solution {
public:
    int MOD = 1e9+33;
    string shortestPalindrome(string s) {
        int n = s.length();
        if(!n) return s;
        unordered_map<char,int> codes;
        for(char ch='a';ch<='z';ch++) {
            codes[ch] = ch-'a'+1;
        }
        long long ind = 0;
        long long hash1 = 0;
        long long hash2 = 0;
        long long radix = 1;
        for(int i=0;i<n;i++) {
            hash1 = (hash1 + codes[s[i]]);
            hash2 = ((hash2 + (codes[s[i]]*radix) % MOD) + MOD) % MOD;
            if(hash1 == hash2) ind = i;
            hash1 = (hash1 * 26) % MOD;
            radix = (radix * 26) % MOD;
        }
        string str = s.substr(ind+1);
        reverse(str.begin(),str.end());
        return str+s;
    }
};