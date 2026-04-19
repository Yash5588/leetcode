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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> levels;
        if(root == nullptr) return {};
        queue<TreeNode*> que;
        que.push(root);
        bool reverse = false;
        while(!que.empty()) {
            int size = que.size();
            vector<int> vec(size);
            for(int i = 0;i < size;i++) {
                TreeNode* node = que.front();
                que.pop();
                int idx = (reverse) ? size-i-1 : i;
                vec[idx] = node->val;
                if(node->left != nullptr) que.push(node->left); 
                if(node->right != nullptr) que.push(node->right); 
            }
            reverse = !reverse;
            levels.push_back(vec);
        }
        return levels;
    }
};