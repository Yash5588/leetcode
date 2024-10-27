struct Node{
    Node* links[2];
    int bit_count = 0;

    bool isContains(int bit) {
        return links[bit] != nullptr;
    }

    Node* get(int bit) {
        return links[bit];
    }

    void put(int bit, Node* node) {
        links[bit] = node;
    }

    void remove(int bit) {
        links[bit] = nullptr;
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
        Node* node = root;
        for(int i = 31;i >= 0;i--) {
            int bit = (num >> i) & 1;
            if(!node->isContains(bit)) {
                node->put(bit, new Node());
            }
            node = node->get(bit);
            node->bit_count++;
        }
    }

    int maxxor(int num) {
        Node* node = root;
        int maxx = 0;
        for(int i = 31;i >= 0;i--) {
            int bit = (num >> i) & 1;
            if(node->isContains(1-bit)) {
                maxx |= (1 << i);
                node = node->get(1-bit);
            } 
            else node = node->get(bit);
        }
        return maxx;
    }

    void deleteNode(int num) {
        Node* node = root;
        Node* prev = root;
        for(int i = 31;i >= 0;i--) {
            int bit = (num >> i) & 1;
            node = node->get(bit);
            if(node->bit_count == 1) {
                prev->remove(bit);
            }
            else {
                node->bit_count--;
            }
            prev = node;
        }
    }
};
class Solution {
public:
    unordered_map<int,vector<pair<int,int>>> ques;
    unordered_map<int,vector<int>> adj;
    vector<int> res;
    void dfs(int node, Trie trie) {
        trie.insert(node);
        for(auto &q : ques[node]) {
            int val = q.first;
            int index = q.second;
            res[index] = trie.maxxor(val);
        }
        for(auto &child : adj[node]) {
            dfs(child,trie);
        }
        trie.deleteNode(node);
    }
    vector<int> maxGeneticDifference(vector<int>& parents, vector<vector<int>>& queries) {
        for(int i = 0;i < queries.size();i++) {
            ques[queries[i][0]].push_back({queries[i][1],i});
        }
        int root;
        for(int i = 0;i < parents.size();i++) {
            if(parents[i] == -1) root = i;
            adj[parents[i]].push_back(i);
        }
        int n = parents.size();
        res.resize(queries.size());
        Trie trie;
        dfs(root,trie);
        return res;
    }
};