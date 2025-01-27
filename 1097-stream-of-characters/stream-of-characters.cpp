struct Node{
    Node* links[26];
    bool flag = false;

    void put(int idx, Node* node) {
        links[idx] = node;
    }

    Node* get(int idx) {
        return links[idx];
    }

    bool isContains(int idx) {
        return links[idx] != nullptr;
    }
};

class Trie{
    Node* root = nullptr;
    public:
        Trie() {
            root = new Node();
        }

        void insert(string &word) {
            Node* node = root;
            for(int i = word.size()-1;i >= 0;i--) {
                int idx = word[i] - 'a';
                if(!node->isContains(idx)) {
                    node->put(idx, new Node());
                }
                node = node->get(idx);
            }
            node->flag = true;
        }

        bool suffix(string &word) {
            Node* node = root;
            for(int i = word.size()-1;i >= 0;i--) {
                int idx = word[i] - 'a';
                if(!node->isContains(idx)) return false; //last characters are not present so there won't be any suffix
                node = node->get(idx);
                if(node->flag) return true;
            }
            return node->flag;
        }
};
class StreamChecker {
public:
    Trie trie;
    StreamChecker(vector<string>& words) {
        for(auto &word : words) trie.insert(word);
    }
    
    string stream;
    bool query(char letter) {
        stream += letter;
        return trie.suffix(stream);
    }
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */