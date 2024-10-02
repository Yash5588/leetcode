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
        //if we get assign camera to null
        //then that path is wrong
        if(root == nullptr) {
            if(placeCam) return INT_MAX;
            return 0;
        }
        if(dp.find({root,{placeCam,parentCam}}) != dp.end()) {
            return dp[{root,{placeCam,parentCam}}];
        }
        //root is safe by either it's parent has camera
        //or root has camera 
        if(placeCam || parentCam) {
            long long left = min(solve(root->left,0,placeCam),solve(root->left,1,placeCam));
            long long right = min(solve(root->right,0,placeCam),solve(root->right,1,placeCam));
            if(placeCam) return dp[{root,{placeCam,parentCam}}] = 1 + left + right;
            return  dp[{root,{placeCam,parentCam}}] = left + right;
        }
        //this case it when root parent doesn't have camera 
        //and root also doesn't have camera
        else {
            long long placeLeft,placeRight;
            //we forcefully assign camera to one child
            //and give choice to another
            placeLeft = solve(root->left,1,placeCam) + min(solve(root->right,1,placeCam),solve(root->right,0,placeCam));
            placeRight = solve(root->right,1,placeCam) + min(solve(root->left,1,placeCam),solve(root->left,0,placeCam));
            return  dp[{root,{placeCam,parentCam}}] = min(placeLeft,placeRight);
        }
    }
    int minCameraCover(TreeNode* root) {
        return min(solve(root,0,0),solve(root,1,0));
    }
};