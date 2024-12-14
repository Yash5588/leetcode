class Solution {
public:
    map<int,unordered_set<string>> levelWords;
    vector<vector<string>> res;
    void backtrack(string &end, string start, vector<string> temp, int currentLevel) {
        if(end == start) {
            //we will get res in reverse so reverse it
            reverse(temp.begin(),temp.end());
            res.push_back(temp);
            //modifying original sequence so re reverse it
            // reverse(temp.begin(),temp.end());
            return;
        }
        unordered_set<string> prevLevel = levelWords[currentLevel-1];
        for(int i = 0;i < end.size();i++) {
            char original = end[i];
            for(char ch = 'a';ch <= 'z';ch++) {
                end[i] = ch;
                if(prevLevel.find(end) != prevLevel.end()) {
                    temp.push_back(end);
                    backtrack(end, start, temp, currentLevel-1);
                    temp.pop_back();
                }
                end[i] = original;
            }
        }
    }
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> words;
        for(auto &str: wordList) {
            words.insert(str);
        }
        //no end word
        if(words.find(endWord) == words.end()) return {};
        //if begin word is present erase it.
        if(words.find(beginWord) != words.end()) {
            words.erase(beginWord);
        }
        queue<pair<string,int>> que;
        que.push({beginWord,0});

        int minSteps = INT_MAX;
        while(!que.empty()) {
            string word = que.front().first;
            int level = que.front().second;
            que.pop();
            levelWords[level].insert(word);
            if(word == endWord) {
                minSteps = level;
                break;
            }
            for(int i = 0;i < word.size();i++) {
                char original = word[i];
                for(char ch = 'a';ch <= 'z';ch++) {
                    word[i] = ch;
                    if(words.find(word) != words.end()) {
                        que.push({word,level+1});
                        //the current word dist is itself shortest so remove from hashset
                        words.erase(word);
                    }
                    word[i] = original;
                }
            }
        }
        //backtrack from end to start and build sequences
        backtrack(endWord, beginWord, {endWord}, minSteps);
        // cout << minSteps << endl;
        // for(auto &[key,val] : levelWords) {
        //     cout << key << endl;
        //     for(auto &s : val) cout << s << endl;
        // }
        return res;
    }
};