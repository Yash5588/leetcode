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
    int idx = 0;
    TreeNode* build(vector<int> &preorder, int upper_bound) {
        if(idx >= preorder.size()) return nullptr;
        if(preorder[idx] > upper_bound) return nullptr;
        TreeNode* root = new TreeNode(preorder[idx++]);
        root->left = build(preorder, root->val);
        root->right = build(preorder, upper_bound);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return build(preorder, INT_MAX);
    }
};