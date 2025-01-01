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
    string res;
    bool isLeaf(TreeNode* root) {
        return root->left == nullptr && root->right == nullptr;
    }
    void postorder(TreeNode* root, string &str) {
        if(!root) {
            return;
        }
        if(isLeaf(root)) {
            str += ('a' + root->val);
            reverse(str.begin(),str.end());
            if(res.empty()) res = str;
            else res = min(res, str);
            reverse(str.begin(),str.end());
            str.pop_back();
            return;
        }
        str += ('a' + root->val);
        postorder(root->left,str);
        postorder(root->right,str);
        str.pop_back();
    }
    string smallestFromLeaf(TreeNode* root) {
        string str;
        postorder(root,str);
        return res;
    }
};