/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    void dfs(Node* new_node, Node* node, unordered_map<Node*,Node*> &visited) {
        if(node == nullptr) return;
        if(visited[node] != nullptr) return;
        visited[node] = new_node;
        for(auto &child : node->neighbors) {
            if(visited[child] != nullptr) {
                new_node->neighbors.push_back(visited[child]);
            }
            else {
                Node* new_child = new Node(child->val, {});
                new_node->neighbors.push_back(new_child);
                dfs(new_child, child, visited);
            }
        }
    }

    Node* cloneGraph(Node* node) {
        unordered_map<Node*,Node*> visited;
        if(node == nullptr) return nullptr;
        Node* new_node = new Node(node->val, {});
        dfs(new_node,node,visited);
        return new_node;
    }
};