class Solution {
public:
    int MOD = 1e9+33;
    int distinctEchoSubstrings(string s) {
        int n = s.size();
        unordered_map<char,int> codes;
        long long total = 0;
        for(char ch='a';ch<='z';ch++) codes[ch] = ch-'a'+1;
        for(int k=1;k<=n/2;k++) {
            unordered_set<long long> hashVal;
            int first = 0,last = 2*k-1;
            long long hash1 = 0,hash2 = 0,radix1 = 1,radix2 = 1;
            for(int i=first;i<=k-1;i++) {
                hash1 = ((hash1 + (codes[s[k-i-1]]*radix1) % MOD) + MOD) % MOD;
                radix1 = (radix1 * 26) % MOD;
            }
            for(int i=last;i>=k;i--) {
                hash2 = ((hash2 + (codes[s[i]]*radix2) % MOD) + MOD) % MOD;
                radix2 = (radix2 * 26) % MOD;
            }
            if(hash1 == hash2) {
                hashVal.insert(hash1);
            }
            for(int i=0;i+k-1<n-k;i++) {
                hash1 = (hash1 * 26) % MOD;
                hash1 = ((hash1 - (codes[s[i]]*radix1) % MOD) + MOD) % MOD;
                hash1 = (hash1 + codes[s[i+k]]) % MOD; 
                hash2 = (hash2 * 26) % MOD;
                hash2 = ((hash2 - (codes[s[k+i]]*radix2) % MOD) + MOD) % MOD;
                hash2 = (hash2 + codes[s[i+2*k]]) % MOD;
                if(hash1 == hash2) hashVal.insert(hash2); 
            }
            total += hashVal.size();
        }
        return total;
    }
};