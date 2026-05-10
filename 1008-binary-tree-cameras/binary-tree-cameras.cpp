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
    int cameras = 0;
    int solve(TreeNode* root, TreeNode* parent) {
        if(root == nullptr) return 1;

        int left = solve(root->left, root);
        int right = solve(root->right, root);

        if(left == 0 || right == 0) {
            cameras++;
            return 2;
        }
        else if(left == 2 || right == 2) return 1;
        else {
            if(parent == nullptr) {
                cameras++;
                return 2;
            }
            return 0;
        }
    }
    int minCameraCover(TreeNode* root) {
        solve(root, nullptr);
        return cameras;
    }
};