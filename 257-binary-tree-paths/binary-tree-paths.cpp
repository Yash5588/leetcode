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
    vector<string> res;
    bool isLeaf(TreeNode* root) {
        return root->left == nullptr && root->right == nullptr;
    }
    void solve(TreeNode* root, string s) {
        if(root == nullptr) {
            return;
        }
        if(isLeaf(root)) {
            res.push_back(s + to_string(root->val));
            return;
        }
        solve(root->left, s + to_string(root->val) + "->");
        solve(root->right, s + to_string(root->val) + "->");
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        solve(root, "");
        return res;
    }
};