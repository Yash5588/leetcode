struct Node{
    Node* links[10];
    int prefixCount = 0;

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

        void insert(int num) {
            string str = to_string(num);
            Node* node = root;
            for(int i=0;i<str.size();i++) {
                int ind = str[i]-'0';
                if(!node->isContains(ind)) {
                    node->put(ind, new Node());
                }
                node = node->get(ind);
                node->prefixCount = i+1;
            }
        }

        int prefix(int num) {
            string str = to_string(num);
            Node* node = root;
            for(int i=0;i<str.length();i++) {
                int ind = str[i]-'0';
                if(!node->isContains(ind)) {
                    return node->prefixCount;
                }
                node = node->get(ind);
            }
            return str.length();
        }
};
class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        Trie trie;
        for(auto &x : arr1) {
            trie.insert(x);
        }
        int ma = INT_MIN;
        for(auto &x : arr2) {
            ma = max(ma, trie.prefix(x));
        }
        return ma;
    }
};