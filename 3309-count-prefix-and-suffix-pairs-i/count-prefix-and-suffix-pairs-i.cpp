struct Node{
    unordered_map<int,Node*> links;
    int count = 0;

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
class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        Node* root = new Node();
        unordered_map<char,int> codes;
        for(char ch='a';ch<='z';ch++) {
            codes[ch] = ch-'a';
        }
        long long total = 0;
        for(auto &s : words) {
            int m = s.size();
            Node* node = root;
            for(int i=0;i<m;i++) {
                int hash = codes[s[i]]*26 + codes[s[m-i-1]];
                if(!node->isContains(hash)) {
                    node->put(hash,new Node());
                }
                node = node->get(hash);
                total += node->count;
            }
            node->count++;
        }
        return total;
    }
};