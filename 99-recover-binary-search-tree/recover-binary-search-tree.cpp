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
    TreeNode* first = nullptr;
    TreeNode* immediate = nullptr;
    TreeNode* second = nullptr;
    TreeNode* prev = nullptr;
    void getNodes(TreeNode* root) {
        if(root == nullptr) return;
        getNodes(root->left);
        if(prev != nullptr && prev->val > root->val) {
            if(first == nullptr) {
                first = prev;
                immediate = root;
            }
            else {
                second = root;
            }
        }
        prev = root;
        getNodes(root->right);
    }
    void recoverTree(TreeNode* root) {
        getNodes(root);
        if(first && second) {
            swap(first->val,second->val);
        }
        else {
            swap(first->val, immediate->val);
        }
    }
};