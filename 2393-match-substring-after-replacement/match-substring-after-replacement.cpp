class Solution {
public:
    bool matchReplacement(string s, string sub, vector<vector<char>>& mappings) {
        int m = sub.length();
        int n = s.length();
        unordered_map<char,unordered_set<char>> mp;

        //populate the map
        for(auto &keys : mappings) {
            mp[keys[0]].insert(keys[1]);
        }

        //traverse each substring and check by replacing
        for(int i = 0;i <= n-m;i++) {
            bool flag = true;
            for(int j = 0;j < m;j++) {
                //check for each char
                if(s[i+j] != sub[j]) {
                    //check if that key is present 
                    //if so then check if it can be replaced
                    //if any of condition fails then string can't be replaced
                    if(mp.find(sub[j]) != mp.end() && mp[sub[j]].find(s[i+j]) != mp[sub[j]].end()) {
                        continue;
                    }
                    else {
                        flag = false;
                        break;
                    }
                }
            }
            if(flag) return true;
        }
        return false;
    }
};