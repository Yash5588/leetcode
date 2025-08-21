class Solution {
public:
    vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries) {
        int n = s.length();
        //we need to calculate the frequencies at each index
        vector<vector<int>> prefix_freq(n+1, vector<int>(26,0));
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < 26;j++) {
                if(j == s[i] - 'a') prefix_freq[i+1][j]++;
                prefix_freq[i+1][j] += prefix_freq[i][j];
            }
        }

        vector<bool> res;
        for(auto &q : queries) {
            int left = q[0];
            int right = q[1];
            int k = q[2];
            int odd = 0;
            for(int j = 0;j < 26;j++) {
                int freq = prefix_freq[right+1][j] - prefix_freq[left][j];
                if(freq & 1) odd++;
            }
            if(odd/2 <= k) res.push_back(true);
            else res.push_back(false);
        }
        return res;
    }
};