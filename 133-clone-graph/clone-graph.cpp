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
        //check if the clone of that node exists
        if(visited[node] != nullptr) return;
        //if not assign
        visited[node] = new_node;
        for(auto &child : node->neighbors) {
            //check if already clone exists for neighbors
            if(visited[child] != nullptr) {
                //if exists then assign it's address
                new_node->neighbors.push_back(visited[child]);
                //it also indicates that this node is already visited
            }
            else {
                //otherwise create a new node
                Node* new_child = new Node(child->val, {});
                new_node->neighbors.push_back(new_child);
                dfs(new_child, child, visited);
            }
        }
    }

    Node* cloneGraph(Node* node) {
        //store original and clone node
        unordered_map<Node*,Node*> visited;
        if(node == nullptr) return nullptr;
        //initially create node
        Node* new_node = new Node(node->val, {});
        dfs(new_node,node,visited);
        return new_node;
    }
};