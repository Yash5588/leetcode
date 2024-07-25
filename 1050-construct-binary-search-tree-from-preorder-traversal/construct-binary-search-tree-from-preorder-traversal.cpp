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
    int split(vector<int> &a, int first, int last) {
        int ind = first+1;
        while(ind < a.size() && a[ind] < a[first]) ind++;
        return ind-1;
    }
    TreeNode* createTree(vector<int> &a, int first, int last) {
        if(first > last) return nullptr;
        TreeNode* root = new TreeNode(a[first]);
        int ind = split(a,first,last);
        root->left = createTree(a,first+1,ind);
        root->right = createTree(a,ind+1,last);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>&a) {
        return createTree(a,0,a.size()-1);
    }
};