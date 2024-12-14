class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> words;
        for(auto &str: wordList) {
            words.insert(str);
        }
        //no end word
        if(words.find(endWord) == words.end()) return 0;
        //if begin word is present erase it.
        if(words.find(beginWord) != words.end()) {
            words.erase(beginWord);
        }
        queue<pair<string,int>> que;
        que.push({beginWord,1});
        while(!que.empty()) {
            string word = que.front().first;
            int level = que.front().second;
            que.pop();
            if(word == endWord) return level;
            for(int i = 0;i < word.size();i++) {
                char original = word[i];
                for(char ch = 'a';ch <= 'z';ch++) {
                    word[i] = ch;
                    if(words.find(word) != words.end()) {
                        que.push({word,level+1});
                        words.erase(word);
                    }
                    word[i] = original;
                }
            }
        }
        return 0;
    }
};