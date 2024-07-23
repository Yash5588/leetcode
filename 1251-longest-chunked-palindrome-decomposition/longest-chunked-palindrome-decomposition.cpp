class Solution {
public:
    int MOD = 1e9+33;
    int longestDecomposition(string s) {
        int n = s.length();
        int first = 0,last = n-1;
        int total = 0;
        unordered_map<char,int> codes;
        for(char ch='a';ch<='z';ch++) {
            codes[ch] = ch-'a'+1;
        }
        long long hash1 = 0,hash2 = 0,radix = 1;
        while(first < last) {
            hash1 = (hash1 * 27) % MOD;
            hash1 = (hash1 + codes[s[first]]) % MOD;
            hash2 = ((hash2 + (codes[s[last]]*radix) % MOD) + MOD) % MOD;
            radix = (radix * 27) % MOD;
            if(hash1 == hash2) {
                total += 2;
                hash1 = hash2 = 0;
                radix = 1;
            }
            first++;
            last--;
        }
        if(n % 2 == 0 && hash1 == 0) return total;
        return total+1;
    }
};