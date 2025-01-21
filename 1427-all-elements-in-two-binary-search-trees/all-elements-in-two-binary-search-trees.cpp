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
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        stack<TreeNode*> sta1,sta2;
        vector<int> res;
        
        while(root1 || root2 || !sta1.empty() || !sta2.empty()) {
            while(root1 != nullptr) {
                sta1.push(root1);
                root1 = root1->left;
            }
            while(root2 != nullptr) {
                sta2.push(root2);
                root2 = root2->left;
            }
            if(sta2.empty() || (!sta1.empty() && sta1.top()->val <= sta2.top()->val)) {
                root1 = sta1.top();
                sta1.pop();
                res.push_back(root1->val);
                root1 = root1->right;
            }
            else {
                root2 = sta2.top();
                sta2.pop();
                res.push_back(root2->val);
                root2 = root2->right;
            }
        }
        return res;
    }
};