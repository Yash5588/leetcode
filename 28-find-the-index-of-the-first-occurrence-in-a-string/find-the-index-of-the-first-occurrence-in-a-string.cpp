class Solution {
public:
    int MOD1 = 1e9+7;
    int MOD2 = 1e9+33;
    int strStr(string s, string pattern) {
        int n = s.length();
        int m = pattern.size();
        long long radix1 = 1,radix2 = 1;
        unordered_map<char,int> codes;
        for(char ch='a';ch<='z';ch++) {
            codes[ch] = ch-'a'+1;
        }
        pair<long long, long long> hash1, hash2;
        if(m > n) return -1;
        for(int i=0;i<m;i++) {
            hash1.first = ((hash1.first + (codes[s[m-i-1]]*radix1) % MOD1) + MOD1) % MOD1;
            hash1.second = ((hash1.second + (codes[s[m-i-1]]*radix2) % MOD2) + MOD2) % MOD2;
            hash2.first = ((hash2.first + (codes[pattern[m-i-1]]*radix1) % MOD1) + MOD1) % MOD1;
            hash2.second = ((hash2.second + (codes[pattern[m-i-1]]*radix2) % MOD2) + MOD2) % MOD2;
            radix1 = (radix1 * 27) % MOD1;
            radix2 = (radix2 * 33) % MOD2;
        }
        if(hash1.first == hash2.first && hash1.second == hash2.second) return 0;
        for(int i=0;i<n-m;i++) {
            hash1.first = (hash1.first * 27) % MOD1;
            hash1.first = ((hash1.first - (codes[s[i]]*radix1) % MOD1) + MOD1) % MOD1;
            hash1.first = (hash1.first + codes[s[m+i]]) % MOD1;
            hash1.second = (hash1.second * 33) % MOD2;
            hash1.second = ((hash1.second - (codes[s[i]]*radix2) % MOD2) + MOD2) % MOD2;
            hash1.second = (hash1.second + codes[s[m+i]]) % MOD2;
            if(hash1.first == hash2.first && hash1.second == hash2.second) return i+1;
        }
        return -1;
    }
};