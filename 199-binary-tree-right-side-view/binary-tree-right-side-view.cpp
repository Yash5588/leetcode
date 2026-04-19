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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> nodes;
        queue<TreeNode*> que;
        if(root == nullptr) return {};
        que.push(root);
        while(!que.empty()) {
            int size = que.size();
            vector<int> vec;
            for(int i = 0;i < size;i++) {
                TreeNode* node = que.front();
                que.pop();
                vec.push_back(node->val);
                if(node->left != nullptr) que.push(node->left);
                if(node->right != nullptr) que.push(node->right);
            }
            nodes.push_back(vec.back());
        }
        return nodes;
    }
};