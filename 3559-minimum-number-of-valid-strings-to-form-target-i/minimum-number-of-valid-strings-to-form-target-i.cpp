struct Node{
    Node* links[26];
    int prefix_length = 0;

    bool isContains(char ch) {
        return links[ch - 'a'] != nullptr;
    } 

    void put(char ch, Node* node) {
        links[ch - 'a'] = node;
    }

    Node* get(char ch) {
        return links[ch - 'a'];
    }
};

class Trie {
    private:
        Node* root = nullptr;
    
    public:
        Trie() {
            root = new Node();
        }

        void insert(string &word) {
            Node* node = root;
            int n = word.length();
            for(int i = 0;i < n;i++) {
                char ch = word[i];
                if(!node->isContains(ch)) {
                    node->put(ch, new Node());
                }
                node = node->get(ch);
                node->prefix_length = i + 1;
            }
        }

        int prefix(string &word) {
            Node* node = root;
            int n = word.length();
            for(int i = 0;i < n;i++) {
                char ch = word[i];
                if(!node->isContains(ch)) {
                    return node->prefix_length;
                }
                node = node->get(ch);
            }
            return node->prefix_length;
        }

};
class Solution {
public:
    int dp[10000];
    int solve(string &target, Trie trie, int pos) {
        int n = target.size();
        if(pos == n) return 0;
        if(pos > n) return 10000;
        if(dp[pos] != -1) return dp[pos];
        string str = target.substr(pos);
        int len = trie.prefix(str);
        int mi = 10000;
        for(int l = 1;l <= len;l++) {
            mi = min(mi, 1 + solve(target,trie,pos+l));
        }
        return dp[pos] = mi;
    }
    int minValidStrings(vector<string>& words, string target) {
        Trie trie;
        for(auto &str : words) {
            trie.insert(str);
        }
        memset(dp,-1,sizeof(dp));
        int res = solve(target,trie,0);
        if(res == 10000) return -1;
        return res;
    }
};