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
    map<pair<TreeNode*,pair<bool,bool>>,long long> dp;
    bool isLeaf(TreeNode* root) {
        return root->left == nullptr && root->right == nullptr;
    }
    long long solve(TreeNode* root, bool placeCam, bool parentCam) {
        if(root == nullptr) {
            if(placeCam) return INT_MAX;
            return 0;
        }
        if(isLeaf(root)) {
            if(placeCam) return 1;
            else {
                if(parentCam) return 0;
                return INT_MAX;
            }
        }
        if(dp.find({root,{placeCam,parentCam}}) != dp.end()) {
            return dp[{root,{placeCam,parentCam}}];
        }
        if(placeCam || parentCam) {
            long long left = min(solve(root->left,0,placeCam),solve(root->left,1,placeCam));
            long long right = min(solve(root->right,0,placeCam),solve(root->right,1,placeCam));
            if(placeCam) return dp[{root,{placeCam,parentCam}}] = 1 + left + right;
            return  dp[{root,{placeCam,parentCam}}] = left + right;
        }
        else {
            long long placeLeft,placeRight;
            placeLeft = solve(root->left,1,placeCam) + min(solve(root->right,1,placeCam),solve(root->right,0,placeCam));
            placeRight = solve(root->right,1,placeCam) + min(solve(root->left,1,placeCam),solve(root->left,0,placeCam));
            return  dp[{root,{placeCam,parentCam}}] = min(placeLeft,placeRight);
        }
    }
    int minCameraCover(TreeNode* root) {
        return min(solve(root,0,0),solve(root,1,0));
    }
};