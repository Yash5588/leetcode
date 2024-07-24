//ROLLING HASH WITH HASH FUNCTION
class Solution {
public:
    int MOD = 1e9+87;
    long long countPrefixSuffixPairs(vector<string>& words) {
        unordered_map<long long,long long> hashCount;
        int m = words[0].size();
        unordered_map<char,int> codes;
        for(char ch='a';ch<='z';ch++) {
            codes[ch] = ch-'a'+1;
        }
        long long total = 0;
        for(auto &str : words) {
            long long prefix = 0, suffix = 0, radix = 1,m = str.size();
            for(int i=0;i<m;i++) {
                prefix = (prefix * 29) % MOD;
                prefix = (prefix + codes[str[i]]) % MOD;
                suffix = ((suffix + (codes[str[m-i-1]]*radix) % MOD) + MOD) % MOD;
                radix = (radix * 29) % MOD;
                if(prefix == suffix) total+=hashCount[prefix];
            }
            hashCount[prefix]++;
        }
        return total;
    }
};