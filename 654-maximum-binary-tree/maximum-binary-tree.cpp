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
        int ma = INT_MIN,ind = first;
        for(int i=first;i<=last;i++) {
            if(ma < a[i]) {
                ma = a[i];
                ind = i;
            }
        }
        TreeNode* root = new TreeNode(ma);
        root->left = createTree(a,first,ind-1);
        root->right = createTree(a,ind+1,last);
        return root;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& a) {
        int n = a.size();
        return createTree(a,0,n-1);
    }
};