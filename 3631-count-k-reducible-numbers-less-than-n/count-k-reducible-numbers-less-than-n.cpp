class Solution {
public:
    vector<int> OperationsToMakeOne;
    long long dp[800][2][800];
    int mod = 1e9+7;
    long long solve(string &s, int pos, bool tight, int setBits, int k) {
        int n = s.length();
        if(pos >= n) {
            if(tight == 1 || setBits == 0) return 0;
            return (OperationsToMakeOne[setBits] <= k) ? 1 : 0;
        }
        if(dp[pos][tight][setBits] != -1) return dp[pos][tight][setBits];
        long long res = 0;
        if(tight) {
            if(s[pos] == '0') {
                res = (res + solve(s, pos+1, 1, setBits, k) % mod) % mod;
            }
            else {
                res = (res + solve(s, pos+1, 1, setBits+1, k) % mod + solve(s, pos+1, 0, setBits, k) % mod) % mod;
            }
        }
        else {
            res = (res + solve(s, pos+1, 0, setBits+1, k) % mod + solve(s, pos+1, 0, setBits, k) % mod) % mod;
        }
        return dp[pos][tight][setBits] = res;
    }
    int countKReducibleNumbers(string s, int k) {
        OperationsToMakeOne.resize(801,0);
        //here we are checking for next stage like for a number which has 800 bits set to get that number it's not possible
        //so the immediate operation for it is 800 right
        //so we calculate for 800 and add 1 to it which represents above mentioned number
        OperationsToMakeOne[1] = 1;
        //store all possible results for each bit combination of set bits
        for(int i = 2;i <= 800;i++) {
            int setBitCount = __builtin_popcount(i);
            OperationsToMakeOne[i] = OperationsToMakeOne[setBitCount] + 1;
        }
        memset(dp,-1,sizeof(dp));
        return solve(s,0,1,0,k);
    }
};