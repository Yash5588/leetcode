class Solution {
public:
    int MOD = 1e9+7;
    bool hasAllCodes(string s, int k) {
        int n = s.length();
        if(n <= k) return false;
        unordered_set<int> hashs;
        int hash = 0;
        int radix = 1;
        map<char,int> codes;
        codes['0'] = 0;
        codes['1'] = 1;
        for(int i=0;i<k;i++) {
            hash = (hash + (codes[s[k-i-1]]*radix) % MOD) % MOD;
            radix = (radix * 2) % MOD;
        }
        hashs.insert(hash);
        for(int i=0;i<n-k;i++) {
            hash = (hash*2)%MOD;
            hash = (hash - (codes[s[i]]*radix) % MOD) % MOD;
            hash = (hash + codes[s[i+k]]) % MOD;
            hashs.insert(hash);
        }
        return hashs.size() == (long long)pow(2,k);
    }
};