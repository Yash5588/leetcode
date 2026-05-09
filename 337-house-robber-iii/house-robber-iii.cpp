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
    map<pair<TreeNode*,bool>,int> dp;
    int solve(TreeNode* root, bool taken) {
        if(root == nullptr) return 0;
        if(dp.find({root,taken}) != dp.end()) return dp[{root,taken}];
        int pick = 0;
        if(!taken) {
            pick = root->val + solve(root->left, true) + solve(root->right, true);
        }
        int not_pick = solve(root->left, false) + solve(root->right, false);
        return dp[{root,taken}] = max(pick, not_pick);
    }
    int rob(TreeNode* root) {
        return solve(root, false);
    }
};