class Solution {
public:
    vector<int> kmp(string &str, string &pattern) {
        string s = pattern + '#' + str;
        int n = s.length();
        vector<int> lps(n,0);
        for(int i = 1;i < n;i++) {
            int prev_index = lps[i-1];
            while(prev_index > 0 && s[i] != s[prev_index]) {
                prev_index = lps[prev_index-1];
            }
            lps[i] = prev_index + (s[i] == s[prev_index]);
        }
        return lps;
    }
    int minValidStrings(vector<string>& words, string target) {
        int len = target.length();
        vector<vector<int>> words_lps;
        //for all the words build the lps array with target
        for(auto &word : words) {
            words_lps.push_back(kmp(target, word));
        }

        int steps = 0;
        while(len > 0) {
            //iterate and check which word matches maximum suffix of target
            int match = 0;
            for(int i = 0;i < words.size();i++) {
                //it is of format "pattern + # + target so we have to move to last index"
                int last_index = words[i].size() + len;
                match = max(match, words_lps[i][last_index]);
            }
            //no word prefix has matched
            if(match == 0) return -1;
            //if matched then reduce length and increment steps
            //we are choosing greedily it will be minimum 
            steps++;
            len -= match;
        }
        return steps;
    }
};