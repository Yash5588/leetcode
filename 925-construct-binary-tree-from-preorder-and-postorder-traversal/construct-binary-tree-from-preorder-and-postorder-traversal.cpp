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
    int pre_ind = 0;
    TreeNode* createTree(vector<int> &preorder,vector<int> &postorder, int start, int end) {
        int n = preorder.size();
        if(start > end) return nullptr;
        if(pre_ind == n-1) return new TreeNode(preorder[pre_ind]);
        TreeNode* root = new TreeNode(preorder[pre_ind]);
        int left_ele = preorder[pre_ind+1];
        pre_ind++;
        auto iter = find(postorder.begin()+start+1, postorder.begin()+end+1, left_ele);
        int ind = iter - postorder.begin();
        root->left = createTree(preorder, postorder, ind, end);
        root->right = createTree(preorder, postorder, start+1, ind-1);
        return root;
    }
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        reverse(postorder.begin(),postorder.end());
        int n = preorder.size();
        return createTree(preorder,postorder,0,n-1);
    }
};