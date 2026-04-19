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
    vector<vector<int>> res;
    bool isLeaf(TreeNode* root) {
        return root->left == nullptr && root->right == nullptr;
    }
    void pathSum(TreeNode* root, int targetSum, vector<int> &temp) {
        if(root == nullptr) return;
        temp.push_back(root->val);
        if(isLeaf(root)) {
            if(targetSum - root->val == 0) {
                res.push_back(temp);
            } 
        }
        pathSum(root->left, targetSum - root->val, temp); 
        pathSum(root->right, targetSum - root->val, temp);
        temp.pop_back(); 
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if(root == nullptr) return {};
        vector<int> temp;
        pathSum(root,targetSum,temp);
        return res;
    }
};