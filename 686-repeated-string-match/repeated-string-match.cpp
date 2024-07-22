class Solution {
public:
    int MOD = 1e9+33;
    int repeatedStringMatch(string a, string b) {
        if(a == b) return 1;
        int n = a.length();
        int m = b.length();
        string str = a;
        unordered_map<char,int> codes;
        for(char ch='a';ch<='z';ch++) {
            codes[ch] = ch-'a'+1;
        }
        for(int i=0;i<((m%n)?m/n:m/n-1);i++) str += a;
        long long hash = 0,radix = 1,phash = 0;
        for(int i=0;i<m;i++) {
            phash = ((phash + (codes[b[m-i-1]]*radix) % MOD) + MOD) % MOD;
            hash = ((hash + (codes[str[m-i-1]]*radix) % MOD) + MOD) % MOD;
            radix = (radix * 27) % MOD;
        }
        cout << str << endl;
        if(hash == phash) {
            if(n < m) return str.length()/n;
            else return 1;
        }
        int i;
        for(i=0;i<str.length()-m;i++) {
            hash = (hash * 27) % MOD;
            hash = ((hash - (codes[str[i]]*radix) % MOD) + MOD) % MOD;
            hash = (hash + codes[str[i+m]]) % MOD;
            if(hash == phash) {
                if(n < m) {
                    return str.length()/n;
                }
                else return 1;
            }
        }
        str += a;
        for(;i<str.length()-m;i++) {
            hash = (hash * 27) % MOD;
            hash = ((hash - (codes[str[i]]*radix) % MOD) + MOD) % MOD;
            hash = (hash + codes[str[i+m]]) % MOD;
            if(hash == phash) {
                return str.length()/n;
            }
        }

        return -1;
    }
};