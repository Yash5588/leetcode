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
    void getZigZag(TreeNode* root, bool right, long long &ma, long long count) {
        if(!root) return;
        ma = max(ma, count);
        getZigZag(root->right ,true ,ma ,(!right)?count+1:1);
        getZigZag(root->left, false, ma, (right)?count+1:1);
    }
    int longestZigZag(TreeNode* root) {
        long long ma = 0;
        getZigZag(root->right,true,ma,1);
        getZigZag(root->left,false,ma,1);
        return ma;
    }
};