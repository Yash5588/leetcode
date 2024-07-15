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
    void countSum(TreeNode* root, int target, unordered_map<long long, int> &prevSum, long long sum, int &count) {
        if(!root) return;
        sum += root->val;
        count += prevSum[sum-target];
        prevSum[sum]++;
        countSum(root->left, target, prevSum, sum, count);
        countSum(root->right, target, prevSum, sum, count);
        prevSum[sum]--;
        sum -= root->val;

    }
    int pathSum(TreeNode* root, int targetSum) {
        if(!root) return 0;
        int count = 0;
        unordered_map<long long, int> prevSum;
        prevSum[0] = 1;
        countSum(root, targetSum, prevSum, 0, count);
        return count;
    }
};