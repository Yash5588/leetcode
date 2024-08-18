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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> postorder; // root right left
        TreeNode* curr = root;
        while(curr != nullptr) {
            if(curr->right == nullptr) {
                postorder.push_back(curr->val);
                curr = curr->left;
            }
            else {
                TreeNode* prev = curr->right;
                //inorder successor
                while(prev->left && prev->left != curr) {
                    prev = prev->left;
                }
                if(prev->left == nullptr) {
                    prev->left = curr;
                    postorder.push_back(curr->val);
                    curr = curr->right;
                }
                else {
                    prev->left = nullptr;
                    curr = curr->left;
                }
            }
        }
        reverse(postorder.begin(),postorder.end()); // left right root
        return postorder;
    }
};