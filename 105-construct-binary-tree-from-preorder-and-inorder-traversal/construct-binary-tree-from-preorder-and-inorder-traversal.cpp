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
    unordered_map<int,int> in_idx;
    TreeNode* build(vector<int> &preorder, int pre_start, int pre_end, vector<int> &inorder, int in_start, int in_end) {
        if(in_start > in_end || pre_start > pre_end) {
            return nullptr;
        }
        TreeNode* root = new TreeNode(preorder[pre_start]);
        int root_idx = in_idx[root->val];
        int num_left = root_idx - in_start;
        root->left = build(preorder, pre_start+1, pre_start+num_left, inorder, in_start, root_idx-1);
        root->right = build(preorder, pre_start+num_left+1, pre_end, inorder, root_idx+1, in_end);
        return root;

    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i = 0;i < inorder.size();i++) {
            in_idx[inorder[i]] = i;
        }
        return build(preorder, 0, preorder.size()-1,
        inorder, 0, inorder.size()-1);
    }
};