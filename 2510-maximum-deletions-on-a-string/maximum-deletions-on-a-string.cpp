class Solution {
public:
    vector<int> zfunc(string &str) {
        int n = str.length();
        vector<int> z(n,0);
        int left = 0,right = 0;
        for(int i = 1;i < n;i++) {
            if(i > right) {
                left = right = i;
                while(right < n && str[right] == str[right-left]) {
                    right++;
                }
                z[i] = right - left;
                right--;
            }
            else {
                int ind = i - left;
                if(i + z[ind] <= right) z[i] = z[ind];
                else {
                    left = i;
                    while(right < n && str[right] == str[right - left]) right++;
                    z[i] = right - left;
                    right--; 
                }
            }
        }
        return z;
    }
    int dp[4000];
    int solve(string &s, int pos, vector<vector<int>> &delets) {
        int n = s.length();
        if(pos >= n) return 0;
        if(pos == n-1) return 1;
        if(dp[pos] != -1) return dp[pos];
        int ma = INT_MIN;
        for(auto &i : delets[pos]) {
            ma = max(ma, 1 + solve(s,pos+i,delets));
        }
        ma = max(ma, 1 + solve(s,n,delets));
        return dp[pos] = ma;
    }
    int deleteString(string s) {
        int n = s.length();
        vector<vector<int>> delets(n, vector<int>());
        for(int i = 0;i < n;i++) {
            string str = s.substr(i);
            // cout << str << endl;
            vector<int> z = zfunc(str);
            // for(auto &x : z) cout << x <
            for(int j = 0;j < str.length();j++) {
                if(j > 0 && z[j] >= j) {
                    delets[i].push_back(j);
                }
            }
        }
        // for(int i = 0;i < n;i++) {
        //     if(delets[i].empty()) continue;
        //     cout << i << ' ' << s.substr(i) << endl;
        //     for(auto &x : delets[i]) {
        //         cout << x << ' ';
        //     }
        //     cout << endl;
        // }
        memset(dp,-1,sizeof(dp));
        return solve(s,0,delets);
    }
};