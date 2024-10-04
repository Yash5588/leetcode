struct Node{
    Node* links[26];
    int prefix_count = 0;

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

class Trie {
    private:
        Node* root = nullptr;
    
    public:
        Trie() {
            root = new Node();
        }

        void insert(string &word) {
            Node* node = root;
            int n = word.size();
            for(int i = 0;i < n;i++) {
                int ind = word[i] - 'a';
                if(!node->isContains(ind)) {
                    node->put(ind, new Node());
                }
                node = node->get(ind);
                node->prefix_count++;
            }
        }

        int score(string &word) {
            int res = 0;
            Node* node = root;
            for(auto &ch : word) {
                int ind = ch - 'a';
                if(!node->isContains(ind)) {
                    node->put(ind, new Node());
                }
                node = node->get(ind);
                res += node->prefix_count;   
            }
            return res;
        }
    };
class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        Trie trie;
        for(auto &word : words) {
            trie.insert(word);
        }
        vector<int> res;
        for(auto &word : words) {
            res.push_back(trie.score(word));
        }
        return res;
    }
};