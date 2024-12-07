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
    TreeNode* createTree(vector<int> &preorder, vector<int> &inorder, int start, int end) {
        int n = inorder.size();
        // if(start == end) {
        //     pre_index++;
        //     return new TreeNode(inorder[start]);
        // }
        if(start > end) return nullptr;
        int ind = find(inorder.begin(),inorder.end(),preorder[pre_index]) - inorder.begin();
        TreeNode* root = nullptr;
        if(ind < n) {
            pre_index++;
            root = new TreeNode(inorder[ind]);
            root->left = createTree(preorder,inorder,start,ind-1);
            root->right = createTree(preorder,inorder,ind+1,end);
        }
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        return createTree(preorder,inorder,0,n-1);
    }
};