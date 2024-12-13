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
    vector<TreeNode*> generateTree(int start, int end) {
        if(start > end) return {nullptr};
        if(start == end) {
            return {new TreeNode(start)};
        }
        vector<TreeNode*> trees;
        for(int i = start;i <= end;i++) { //make all the values as nodes
            vector<TreeNode*> leftTrees = generateTree(start, i-1);
            vector<TreeNode*> rightTrees = generateTree(i+1, end);

            for(auto left : leftTrees) {
                for(auto right : rightTrees) {
                    TreeNode* root = new TreeNode(i);
                    root->left = left;
                    root->right = right;
                    trees.push_back(root);
                }
            }
        }
        return trees;

    }
    vector<TreeNode*> generateTrees(int n) {
        return generateTree(1,n); //start and end indices
    }
};