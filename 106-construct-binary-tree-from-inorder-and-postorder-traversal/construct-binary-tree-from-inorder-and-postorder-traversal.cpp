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
    TreeNode* build(vector<int> &inorder, int in_start, int in_end, vector<int> &postorder, int post_start, int post_end) {
        if(in_start > in_end || post_start > post_end) {
            return nullptr;
        }
        TreeNode* root = new TreeNode(postorder[post_start]);
        int root_idx = in_idx[root->val];
        int num_right = in_end - root_idx;
        root->right = build(inorder, root_idx + 1, in_end, postorder, post_start + 1, post_start + num_right);
        root->left = build(inorder, in_start, root_idx - 1, postorder, post_start + num_right + 1, post_end);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        reverse(postorder.begin(),postorder.end());
        for(int i = 0;i < inorder.size();i++) {
            in_idx[inorder[i]] = i;
        }
        return build(inorder, 0, inorder.size()-1, postorder, 0, postorder.size()-1);
    }
};