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
    vector<int> vec;
    int pos = 0;
    bool solve(TreeNode* root, vector<int> &voyage) {
        if(!root) return true;
        if(root->val != voyage[pos]) return false;
        else {
            pos++;
            if(root->left && voyage[pos] != root->left->val) {
                vec.push_back(root->val);
                TreeNode* temp = root->left;
                root->left = root->right;
                root->right = temp;
            }
            return solve(root->left,voyage) & solve(root->right,voyage);
        }
    }
    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
        if(solve(root,voyage)) return vec;
        return {-1};
    }
};