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
    TreeNode* replaceValueInTree(TreeNode* root) {
        queue<pair<TreeNode*,TreeNode*>> que;
        que.push({root,nullptr});
        root->val = 0;
        while(!que.empty()) {
            int size = que.size();
            unordered_map<TreeNode*,int> par;
            int sum = 0;
            while(size--) {
                TreeNode* node = que.front().first;
                TreeNode* parent = que.front().second;
                que.pop();
                par[parent] += node->val;
                sum += node->val;
                que.push({node,parent});
            }
            size = que.size();
            while(size--) {
                TreeNode* node = que.front().first;
                TreeNode* parent = que.front().second;
                que.pop();
                node->val = sum - par[parent];
                if(node->left) que.push({node->left,node});
                if(node->right) que.push({node->right,node});
            }
        }
        return root;
    }
};