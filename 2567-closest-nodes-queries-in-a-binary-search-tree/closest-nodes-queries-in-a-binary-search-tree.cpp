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
    vector<int> order;
    void inorder(TreeNode* root) {
        if(root) {
            inorder(root->left);
            order.push_back(root->val);
            inorder(root->right);
        }
    }
    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        vector<vector<int>> res;
        inorder(root);
        int n = order.size();
        for(auto &x : queries) {
            int ind = lower_bound(order.begin(),order.end(),x) - order.begin();
            if(ind != n) {
                if(order[ind] == x) res.push_back({x,x});
                else {
                    if(ind > 0) res.push_back({order[ind-1],order[ind]});
                    else res.push_back({-1,order[ind]});
                }
            }
            else res.push_back({order[ind-1],-1});
        }
        return res;
    }
};