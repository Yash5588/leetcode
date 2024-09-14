struct Node{
    Node* links[2];

    bool isContains(int bit) {
        return links[bit] != nullptr;
    }

    void put(int bit, Node* node) {
        links[bit] = node;
    }

    Node* get(int bit) {
        return links[bit];
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
                    node->put(bit,new Node());
                }
                node = node->get(bit);
            }
        }

        int maxxor(int num) {
            int ans = 0;
            Node* node = root;
            for(int i = 31;i >= 0;i--) {
                int bit = (num >> i) & 1;
                if(node->isContains(1 - bit)) {
                    ans |= (1 << i);
                    node = node->get(1-bit);
                }
                else {
                    node = node->get(bit);
                }
            }
            return ans;
        }
};
class Solution {
public:
    static bool sortBySec(vector<int> &a, vector<int> &b) {
        return a[1] < b[1];
    }
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int qsize = queries.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>> query;
        for(int i = 0;i < qsize;i++) {
            queries[i].push_back(i);
        }
        sort(queries.begin(),queries.end(),sortBySec);
        int i = 0;
        Trie trie;
        vector<int> res(qsize);
        bool start = false;
        for(auto &q : queries) {
            while(i < n && nums[i] <= q[1]) {
                trie.insert(nums[i]);
                start = true;
                i++;
            }
            if(start) res[q[2]] = trie.maxxor(q[0]);
            else res[q[2]] = -1;
        }
        return res;
    }
};