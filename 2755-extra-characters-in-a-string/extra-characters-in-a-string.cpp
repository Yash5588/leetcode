struct Node{
    Node* links[26];
    bool flag = false;

    bool isContains(int ind) {
        return links[ind] != nullptr;
    }

    void put(int ind, Node* node) {
        links[ind] = node;
    }

    Node* get(int ind) {
        return links[ind];
    }
};

class Trie{
    private:
        Node* root = nullptr;
    
    public:
        Trie() {
            root = new Node();
        }

        void insert(string &s) {
            Node* node = root;
            for(auto &x : s) {
                int ind = x-'a';
                if(!node->isContains(ind)) {
                    node->put(ind,new Node());
                }
                node = node->get(ind);
            }
            node->flag= true;
        }

        bool search(string &s) {
            Node* node = root;
            for(auto &x : s) {
                int ind = x-'a';
                if(!node->isContains(ind)) {
                    return false;
                }
                node = node->get(ind);
            }
            return node->flag;
        }
};
class Solution {
public:
    long long dp[52];
    long long split(string &s, int pos, Trie trie) {
        if(pos >= s.length()) return 0;
        if(dp[pos] != -1) return dp[pos];
        long long mi = INT_MAX;
        string str;
        int total = 0;
        for(int i=pos;i<s.length();i++) {
            str += s[i];
            if(!trie.search(str)) {
                total++;
            }
            else total=0;
            mi = min(mi, total + split(s,i+1,trie));
        }
        return dp[pos] = mi;
    }
    int minExtraChar(string s, vector<string>& dict) {
        Trie trie;
        for(auto &x : dict) {
            trie.insert(x);
        }
        memset(dp,-1,sizeof(dp));
        return split(s,0,trie);
    }
};