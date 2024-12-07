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
    int post_index = 0;
    TreeNode* createTree(vector<int> &inorder, vector<int> &postorder, int start, int end) {
        if(start > end) {
            return nullptr;
        }
        int n = inorder.size();
        TreeNode* root = nullptr;
        int ele = postorder[post_index];
        int ind = find(inorder.begin(),inorder.end(),ele) - inorder.begin();
        if(ind < n) {
            post_index++;
            root = new TreeNode(ele);
            root->right = createTree(inorder,postorder,ind+1,end);
            root->left = createTree(inorder,postorder,start,ind-1);
        }
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        //if we reverse the postorder array it is nothing
        //but preorder with root right left
        reverse(postorder.begin(),postorder.end());
        return createTree(inorder,postorder,0,inorder.size()-1);
    }
};