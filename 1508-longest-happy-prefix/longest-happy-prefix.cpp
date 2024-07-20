class Solution {
public:
    int MOD = 1e9+33;
    string longestPrefix(string s) {
        int n = s.length();
        if(n <= 1) return "";
        long long prefix = 0,suffix = 0;
        unordered_map<char,int> codes;
        for(char ch='a';ch<='z';ch++) {
            codes[ch] = ch-'a'+1;
        }
        int m = n-1;
        string ans;
        long long hash1 = codes[s[0]];
        long long hash2 = codes[s[n-1]];
        long long radix = 26;
        long long ind = -1;
        if(hash1 == hash2) ind = 0;
        for(int i=1;i<m;i++) {
            hash1 = (hash1 * 26) % MOD;
            hash1 = (hash1 + codes[s[i]]) % MOD;
            hash2 = ((hash2 + (codes[s[n-i-1]] * radix) % MOD) + MOD) % MOD;
            radix = (radix * 26) % MOD;
            // cout << hash1 << ' ' << hash2 << ' ' <<  i << endl;
            if(hash1 == hash2)  ind = i;
        }
        ans = s.substr(0,ind+1);
        return ans;
        

    }
};