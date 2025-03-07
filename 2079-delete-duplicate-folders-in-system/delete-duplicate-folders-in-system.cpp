
struct Node{
    map<string,Node*> links;
    string name;
    bool isEnd;
    bool exclude;
    Node(string fname) {
        name = fname;
        isEnd = false;
        exclude = false;
    }

    bool isContains(string &word) {
        return links.find(word) != links.end();
    }

    void put(string &word, Node* node) {
        links[word] = node;
    }

    Node* get(string &word) {
        return links[word];
    }
};

class Trie{
    public:
        Node* root = nullptr;
        Trie() {
            root = new Node("/");
        }

        void insert(vector<string> &path) {
            int n = path.size();
            Node* node = root;
            for(auto &word : path) {
                if(!node->isContains(word)) {
                    node->put(word, new Node(word));
                }
                node = node->get(word);
            }
            node->isEnd = true;
        }


};

class Solution {
public:
    unordered_map<string,vector<Node*>> parent_map;
    vector<vector<string>> ans;

    string dfs(Node* root) {
        string childPath = "";
        for(auto &child : root->links) {
            childPath += dfs(child.second);
            childPath += "|";
        }
        //if not leaf node
        if(childPath != "") {
            //for the child path we are going to store all the 
            //parents who have same path
            parent_map[childPath].push_back(root);
        }
        //add root also to path and send to parents
        return root->name + "|" + childPath;

    }

    void getResult(Node* root, vector<string> &temp) {
        if(root->exclude) return;
        if(root->isEnd) ans.push_back(temp);
        for(auto &child : root->links) {
            temp.push_back(child.first);
            getResult(child.second, temp);
            temp.pop_back();
        }
    }
    vector<vector<string>> deleteDuplicateFolder(vector<vector<string>>& paths) {
        //build the trie
        Trie trie;
        for(auto &path : paths) {
            trie.insert(path);
        }

        //serialize the sub folder structure for each node
        Node* root = trie.root;
        dfs(root);


        //exclude all the parents who have same child path
        for(auto &[childPath, parents] : parent_map) {
            if(parents.size() > 1) {
                for(auto &parent : parents) {
                    parent->exclude = true;
                }
            }
        }

        vector<string> temp;
        getResult(root, temp);
        return ans;
    }
};