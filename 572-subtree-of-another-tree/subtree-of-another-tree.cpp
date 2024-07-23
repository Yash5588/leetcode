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
    bool flag = false;
    bool check(TreeNode* root, TreeNode* subRoot) {
        if(!root && !subRoot) return true;
        if(!root || !subRoot) return false;
        if(root->val == subRoot->val) {
            bool ans = true;
            ans &= check(root->left,subRoot->left);
            ans &= check(root->right,subRoot->right);
            return ans;
        }
        return false;
    }
    void postorder(TreeNode* root, TreeNode* subRoot) {
        if(!root) return;
        if(flag) return;
        if(root->val == subRoot->val) {
            flag = check(root,subRoot);
        }
        postorder(root->left,subRoot);
        postorder(root->right,subRoot);
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        postorder(root,subRoot);
        return flag;
    }
};