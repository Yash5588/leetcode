/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isPresent(TreeNode* root) {
        if(!root) return false;
        if(root->val == 1) return true;
        return isPresent(root->left) | isPresent(root->right);
    }

    void preorder(TreeNode* root, TreeNode* parent) {
        if(root) {
            if(!isPresent(root)) {
                if(parent->left == root) parent->left = nullptr;
                if(parent->right == root) parent->right = nullptr;
                return;
            }
            preorder(root->left,root);
            preorder(root->right,root);
        }
    }
    TreeNode* pruneTree(TreeNode* root) {
        if(!isPresent(root)) return nullptr;
        preorder(root,root);
        return root;
    }
};