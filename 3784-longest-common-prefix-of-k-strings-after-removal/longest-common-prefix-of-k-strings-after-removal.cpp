struct Node {
    Node *links[26];
    int count = 0;
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

multiset<int,greater<int>> mset;

class Trie{
    Node* root = nullptr;
    public:
    Trie() {
        root = new Node();
    }

    void insert(string &word, int k) {
        Node* node = root;
        int n = word.size();
        for(int i = 0;i < n;i++) {
            int idx = word[i] - 'a';
            if(!node->isContains(idx)) {
                node->put(idx, new Node());
            }
            node = node->get(idx);
            node->count++;
            if(node->count >= k) mset.insert(i+1);
        }
        node->flag = true;
    }

    void delete_word(string &word, int k) {
        int n = word.size();
        Node* node = root;
        for(int i = 0;i < n;i++) {
            int idx = word[i] - 'a';
            node = node->get(idx);
            if(node->count >= k) {
                mset.erase(mset.find(i+1));
            }
            node->count--;
        }
        node->flag = false;
    }
};
class Solution {
public:
    vector<int> longestCommonPrefix(vector<string>& words, int k) {
        mset.clear();
        int n = words.size();
        Trie trie;
        for(auto &word : words) trie.insert(word,k);
        vector<int> res;
        for(int i = 0;i < n;i++) {
            trie.delete_word(words[i],k);
            if(mset.empty()) res.push_back(0);
            else res.push_back(*mset.begin());
            trie.insert(words[i],k);
        }
        // for(auto &x : mset) cout << x << endl;
        // trie.delete_word(words[0],k);
        // cout << endl;
        // for(auto &x : mset) cout << x << endl;
        return res;
    }
};