/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    bool isLeaf(Node* root) {
        return root->left == nullptr && root->right == nullptr;
    }
    Node* connect(Node* root) {
        if(!root || isLeaf(root)) return root;
        root->left->next = root->right;
        Node* lnode = root->left;
        Node* rnode = root->right;
        while(lnode->right) {
            lnode->right->next = rnode->left;
            lnode = lnode->right;
            rnode = rnode->left;   
        }
        connect(root->left);
        connect(root->right);
        return root;
    }
};