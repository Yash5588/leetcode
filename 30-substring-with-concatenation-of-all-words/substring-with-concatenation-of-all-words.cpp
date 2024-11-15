class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;
        unordered_map<string,int> word_count;
        for(auto &word : words) {
            word_count[word]++;
        }
        int len = words[0].size();
        int m = words.size();
        int n = s.length();
        for(int i = 0;i < len;i++) {
            int count = 0;
            unordered_map<string,int> temp;
            for(int j = i,k = i;j <= n-len;j += len) {
                string word = s.substr(j,len);
                temp[word]++;
                count++;
                if(count == m) {
                    if(temp == word_count) res.push_back(k);
                    string remove = s.substr(k,len);
                    temp[remove]--;
                    count--;
                    if(temp[remove] == 0) temp.erase(remove);
                    k += len;
                }
            }
        }
        return res;
    }
};