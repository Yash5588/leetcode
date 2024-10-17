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
    unordered_map<int,int> left;
    unordered_map<int,int> right;
    
    int height(TreeNode* root) {
        if(!root) return 0;
        int l = height(root->left);
        int r = height(root->right);
        left[root->val] = l;
        right[root->val] = r;
        return 1 + max(l,r);
    }

    unordered_map<int,int> h;
    void solve(TreeNode* root, int depth, int maxHeight) {
        if(root) {
            if(root->left) {
                int remove = right[root->val] + depth;
                h[root->left->val] = max(remove, maxHeight);
                solve(root->left,depth+1,h[root->left->val]);
                // if(root->val == 5) cout << h[root->left->val] << endl;
            }
            if(root->right) {
                int remove = left[root->val] + depth;
                h[root->right->val] = max(remove, maxHeight);
                solve(root->right,depth+1,h[root->right->val]);
            }
        }
    }
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        height(root);
        if(root->left) h[root->left->val] = right[root->val];
        if(root->right) h[root->right->val] = left[root->val];
        solve(root->left,1,right[root->val]);
        solve(root->right,1,left[root->val]);
        vector<int> ans;
        for(auto &x : queries) {
            ans.push_back(h[x]);
        }
        return ans;
    }
};