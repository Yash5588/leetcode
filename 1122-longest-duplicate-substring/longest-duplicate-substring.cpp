class Solution {
public:
    long long MOD1 = 1e9+33;
    long long MOD2 = 1e9+97;
    string longestDupSubstring(string s) {
        int n = s.length();
        unordered_map<char,int> codes;
        for(int ch = 'a';ch <= 'z';ch++) {
            codes[ch] = ch - 'a' + 1;
        }
        int low = 0,high = n-1;
        string ans;
        while(low <= high){
            int m = low + (high - low)/2;
            bool flag = false;
            long long radix1 = 1,radix2 = 1;
            pair<long long,long long> hash = {0,0};
            for(int i=0;i<m;i++) {
                hash.first = ((hash.first + (codes[s[m-i-1]]*radix1) % MOD1) + MOD1) % MOD1;
                radix1 = (radix1 * 27) % MOD1;
                hash.second = ((hash.second + (codes[s[m-i-1]]*radix2) % MOD2) + MOD2) % MOD2;
                radix2 = (radix2 * 33) % MOD2;
            }
            set<pair<long long,long long>> hashcount;
            hashcount.insert(hash);
            for(int i=0;i<n-m;i++) {
                hash.first = (hash.first * 27) % MOD1;
                hash.first = ((hash.first - (codes[s[i]]*radix1) % MOD1) + MOD1) % MOD1;
                hash.first = (hash.first + codes[s[m+i]]) % MOD1;
                hash.second = (hash.second * 33) % MOD2;
                hash.second = ((hash.second - (codes[s[i]]*radix2) % MOD2) + MOD2) % MOD2;
                hash.second = (hash.second + codes[s[m+i]]) % MOD2;
                if(hashcount.count(hash)) {
                    ans = s.substr(i+1,m);
                    flag = true;
                    break;
                }
                hashcount.insert(hash);
            }
            if(flag) {
                low = m+1;
            }
            else {
                high = m-1;
            }
        }
        if(ans.empty()) {
            vector<bool> check(26,false);
            string str;
            for(auto &x : s) {
                if(check[x-'a']) return str+x;
                check[x-'a'] = true;
            }
        }
        return ans;
    }
};