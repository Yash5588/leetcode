class Solution {
public:
    unordered_set<int> indices;
    int dp[3001][3001];
    int solve(string &s, string &pat, int pos1, int pos2) {
        int n = s.length();
        int m = pat.length();
        if(dp[pos1][pos2] != -1) return dp[pos1][pos2];
        if(pos1 >= n) {
            if(pos2 >= m) return 0;
            return INT_MIN;
        }
        int ans = INT_MIN;
        //check if the current character can be included in the subsequence
        if(s[pos1] == pat[pos2]) {
            //if both characters are equal then you have choice
            //we can consider it as subsequence or remove it 
            //if it is present in indices
            ans = max(ans, solve(s,pat,pos1+1,pos2+1));
            if(indices.find(pos1) != indices.end()) {
                ans = max(ans, 1 + solve(s,pat,pos1+1,pos2));
            }
        }
        else {
            //if both characters are not equal or 2nd string is
            //exhausted
            //here also we can remove characters
            //if we can remove it we will remove it
            //otherwise we won't include that character
            if(indices.find(pos1) != indices.end()) {
                ans = max(ans, 1 + solve(s,pat,pos1+1,pos2));
            }
            else {
                ans = max(ans, solve(s,pat,pos1+1,pos2));
            }
        }
        return dp[pos1][pos2] = ans;
    }
    int maxRemovals(string s, string pat, vector<int>& ind) {
        for(auto &x : ind) {
            indices.insert(x);
        }
        memset(dp,-1,sizeof(dp));
        return solve(s,pat,0,0);
    }
};