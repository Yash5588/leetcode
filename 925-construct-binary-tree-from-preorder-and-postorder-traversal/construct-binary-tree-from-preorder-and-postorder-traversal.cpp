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
    unordered_map<int,int> post_idx;
    TreeNode* build(vector<int> &preorder, int pre_start, int pre_end, vector<int> &postorder, int post_start, int post_end) {
        if(pre_start > pre_end || post_start > post_end) return nullptr;
        if(pre_start == pre_end && post_start == post_end) return new TreeNode(preorder[pre_start]);
        TreeNode* root = new TreeNode(preorder[pre_start]);
        int left_root_idx = post_idx[preorder[pre_start+1]];
        int left_size = post_end - left_root_idx + 1;
        root->left = build(preorder, pre_start + 1, pre_start + left_size, postorder, left_root_idx, post_end);
        root->right = build(preorder, pre_start + left_size + 1, pre_end, postorder, post_start+1, left_root_idx-1);
        return root;
    }
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        reverse(postorder.begin(),postorder.end());
        for(int i = 0;i < postorder.size();i++) {
            post_idx[postorder[i]] = i;
        }
        return build(preorder, 0, preorder.size()-1, postorder, 0, postorder.size()-1);
    }
};