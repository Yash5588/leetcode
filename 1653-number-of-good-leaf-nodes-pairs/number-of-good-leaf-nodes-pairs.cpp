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
    bool isLeaf(TreeNode* root) {
        return root->left == nullptr && root->right == nullptr;
    }
    vector<int> getGood(TreeNode* root, int dist, long long &ans) {
        if(!root) return {};
        if(isLeaf(root)) return {1};
        vector<int> left = getGood(root->left, dist, ans);
        vector<int> right = getGood(root->right, dist, ans);
        for(int i=0;i<left.size();i++) {
            for(int j=0;j<right.size();j++) {
                if(left[i] + right[j] <= dist) {
                    ans++;
                }
            }
        }
        vector<int> res;
        for(auto &x : left) {
            if(x != dist) res.push_back(x+1);
        }
        for(auto &x : right) {
            if(x != dist) res.push_back(x+1);
        }
        return res;
    }
    int countPairs(TreeNode* root, int distance) {
        long long ans = 0;
        getGood(root, distance, ans);
        return ans;
    }
};