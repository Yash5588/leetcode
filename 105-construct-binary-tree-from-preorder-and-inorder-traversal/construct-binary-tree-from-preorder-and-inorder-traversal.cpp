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
    int pre_index = 0;
    unordered_map<int,int> inorder_hash;
    TreeNode* createTree(vector<int> &preorder, int start, int end) {
        int n = preorder.size();
        if(start > end) return nullptr;
        int ele = preorder[pre_index];
        int ind = inorder_hash[ele];
        TreeNode* root = nullptr;
        pre_index++;
        root = new TreeNode(ele);
        root->left = createTree(preorder,start,ind-1);
        root->right = createTree(preorder,ind+1,end);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        for(int i = 0;i < n;i++) {
            inorder_hash[inorder[i]] = i;
        }
        return createTree(preorder,0,n-1);
    }
};