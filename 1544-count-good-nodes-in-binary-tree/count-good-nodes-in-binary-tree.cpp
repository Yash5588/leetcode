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
    int Nodes(TreeNode* root, int mval) {
        if(!root) return 0;
        int c = 0;
        if(root->val >= mval) c++;
        c += Nodes(root->left, max(mval, root->val));
        c += Nodes(root->right, max(mval, root->val));
        return c;
    } 
    int goodNodes(TreeNode* root) {
        return Nodes(root,INT_MIN);
    }
};