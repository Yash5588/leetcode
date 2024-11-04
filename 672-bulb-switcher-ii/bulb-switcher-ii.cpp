class Solution {
public:
    map<pair<string,int>,bool> dp;
    void solve(int n, int passes, string &original, unordered_set<string> &se) {
        if(passes == 0) {
            se.insert(original);
            return;
        }

        string str = original;
        //button 1
        for(int i = 0;i < n;i++) {
            if(str[i] == '0') str[i] = '1';
            else str[i] = '0';
        }
        if(dp[{str,passes}] == false) {
            solve(n,passes-1,str,se);
            dp[{str,passes}] = true;
        }
        str = original;

        //button 2
        for(int i = 0;i < n;i += 2) {
            if(str[i] == '0') str[i] = '1';
            else str[i] = '0';
        }
        if(dp[{str,passes}] == false) {
            solve(n,passes-1,str,se);
            dp[{str,passes}] = true;
        }
        str = original;

        //button 3
        for(int i = 1;i < n;i += 2) {
            if(str[i] == '0') str[i] = '1';
            else str[i] = '0';
        }
        if(dp[{str,passes}] == false) {
            solve(n,passes-1,str,se);
            dp[{str,passes}] = true;
        }
        str = original;

        //button 4
        for(int i = 0;i < n;i += 3) {
            if(str[i] == '0') str[i] = '1';
            else str[i] = '0';
        }
        if(dp[{str,passes}] == false) {
            solve(n,passes-1,str,se);
            dp[{str,passes}] = true;
        }
    }

    int flipLights(int n, int presses) {
        string str;
        for(int i = 0;i < n;i++) str += '1';
        unordered_set<string> se;
        solve(n,presses,str,se);
        return se.size();
    }
};