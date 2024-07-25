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
    TreeNode* createTree(vector<int> &a, int first, int last) {
        if(first > last) return nullptr;
        int i = max_element(a.begin()+first,a.begin()+last+1) - a.begin();
        TreeNode* root = new TreeNode(a[i]);
        root->left = createTree(a,first,i-1);
        root->right = createTree(a,i+1,last);
        return root;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& a) {
        int n = a.size();
        return createTree(a,0,n-1);
    }
};