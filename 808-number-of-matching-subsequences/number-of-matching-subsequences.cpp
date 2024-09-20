class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        int n = s.length();
        unordered_map<int,vector<int>> mp;
        for(int i = 0;i < n;i++) {
            mp[s[i]].push_back(i);
        }
        int ans = 0;
        for(auto &str : words) {
            int max = -1;
            bool flag = true;
            for(auto &ch : str) {
                auto iter = upper_bound(mp[ch].begin(),mp[ch].end(),max);
                if(iter == mp[ch].end()) {
                    flag = false;
                    break;
                }
                max = *iter;
            }
            ans += flag; 
        }
        return ans;
    }
};