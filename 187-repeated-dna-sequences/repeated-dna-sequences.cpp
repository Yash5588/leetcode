class Solution {
public:
    int MOD = 1e9+7;
    int hashVal(char ch) {
        switch(ch) {
            case 'A' : return 0;
            case 'C' : return 1;
            case 'G' : return 2;
            case 'T' : return 3;
            default : return 0;
        }
    }
    vector<string> findRepeatedDnaSequences(string s) {
        int n = s.length();
        if(n <= 10) return {};
        int hash = 0;
        int radix = 1;
        for(int i=0;i<10;i++) {
            hash = (hash + (hashVal(s[9-i])*radix) % MOD) % MOD;
            radix = (radix * 4) % MOD;
        }
        radix /= 4;
        unordered_map<int,int> hashcount;
        hashcount[hash]++;
        vector<string> ans;
        for(int i=0;i<n-10;i++) {
            hash = ((hash % MOD) - (hashVal(s[i])*radix) % MOD) % MOD;
            hash = (hash * 4) % MOD;
            hash = (hash + hashVal(s[i+10])) % MOD;
            if(hashcount[hash] != -1) {
                hashcount[hash]++;
            }
            if(hashcount[hash] > 1) {
                ans.push_back(s.substr(i+1,10));
                hashcount[hash] = -1;
            }
        }
        return ans;

    }
};