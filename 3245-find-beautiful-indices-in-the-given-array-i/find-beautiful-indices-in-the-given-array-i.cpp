class Solution {
public:
    int MOD = 1e9+7;
    vector<int> beautifulIndices(string s, string a, string b, int k) {
        int n = s.length(), alen = a.length(), blen = b.length();
        if(n < alen || n < blen) return {};
        unordered_map<char,int> codes;
        for(char ch = 'a';ch <= 'z';ch++) {
            codes[ch] = ch - 'a' + 1;
        }
        vector<int> ind1,ind2;
        long long ahash = 0;
        long long bhash = 0;
        long long hash = 0;
        long long radix1 = 1;
        long long radix2 = 1;
        for(int i=0;i<alen;i++) {
            ahash = ((ahash + (codes[a[alen-i-1]]*radix1) % MOD) + MOD) % MOD;
            hash = ((hash + (codes[s[alen-i-1]]*radix1) % MOD) + MOD) % MOD;
            radix1 = (((radix1 * 26) % MOD) + MOD) % MOD;//
        }
        if(hash == ahash) ind1.push_back(0);
        for(int i=0;i<n-alen;i++) {
            hash = (hash * 26) % MOD;
            hash = ((hash - (codes[s[i]]*radix1) % MOD) + MOD) % MOD;
            hash = (hash + codes[s[i+alen]]) % MOD;
            if(hash == ahash) {
                ind1.push_back(i+1);
            }
        }
        hash = 0;
        for(int i=0;i<blen;i++) {
            bhash = ((bhash + (codes[b[blen-i-1]]*radix2) % MOD) + MOD) % MOD;
            hash = ((hash + (codes[s[blen-i-1]]*radix2) % MOD) + MOD) % MOD;
            radix2 = (radix2 * 26) % MOD;
        }
        if(hash == bhash) ind2.push_back(0);
        for(int i=0;i<n-blen;i++) {
            hash = (hash * 26) % MOD;
            hash = ((hash - (codes[s[i]]*radix2) % MOD) + MOD) % MOD;
            hash = (hash + codes[s[i+blen]]) % MOD;
            if(hash == bhash) {
                ind2.push_back(i+1);
            }
        }
        vector<int> ans;
        for(auto &x : ind1) {
            int low = 0,high = ind2.size()-1;
            while(low <= high) {
                int mid = (low + high)/2;
                if(ind2[mid] > x + k) {
                    high = mid-1;
                }
                else if(ind2[mid] < x-k) {
                    low = mid+1;
                }
                else {
                    ans.push_back(x);
                    break;
                }
            }
        }
        return ans;
    }
};