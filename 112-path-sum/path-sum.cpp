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
    bool isLeaf(TreeNode* root) {
        return root->left == nullptr && root->right == nullptr;
    }
    bool pathSum(TreeNode* root, int targetSum) {
        if(root == nullptr) return false;
        if(isLeaf(root)) {
            return targetSum - root->val == 0;
        }
        return pathSum(root->left,targetSum - root->val) |
        pathSum(root->right,targetSum - root->val);

    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root == nullptr) return false;
        return pathSum(root,targetSum);
    }
};