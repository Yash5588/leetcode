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
    int mxm = INT_MIN;
    int diameter(TreeNode* root) {
        if(root == nullptr) return 0;
        int left = diameter(root->left);
        int right = diameter(root->right);
        mxm = max(mxm, left+right+1);
        return max(left,right) + 1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
       diameter(root);
       return mxm-1; 
    }
};