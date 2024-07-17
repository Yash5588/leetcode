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
    vector<TreeNode*> ans;
    void findDel(TreeNode* root, TreeNode* parent, vector<bool> &isFound) {
        if(!root) return;
        findDel(root->left,root,isFound);
        findDel(root->right,root,isFound);
        if(isFound[root->val]) {
            if(root->left) ans.push_back(root->left);
            if(root->right) ans.push_back(root->right);
            if(parent->left == root) parent->left = NULL;
            if(parent->right == root) parent->right = NULL;
        }
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<bool>isFound(1001,false);
        for(auto &x : to_delete) {
            isFound[x] = true;
        }
        findDel(root,root,isFound);
        if(!isFound[root->val]) ans.push_back(root);
        return ans;
    }
};