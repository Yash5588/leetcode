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
    unordered_map<int,TreeNode*> parents;
    unordered_map<int,TreeNode*> roots;
    unordered_map<int,bool> visited;
    bool isLeaf(TreeNode* root) {
        return root->left == nullptr && root->right == nullptr;
    }
    vector<int> vals;
    void inorder(TreeNode* root) {
        if(root) {
            inorder(root->left);
            vals.push_back(root->val);
            inorder(root->right);
        }
    }
    void dfs(TreeNode* root, int &cnt) {
        if(root == nullptr) return;
        if(isLeaf(root)) {
            if(visited[root->val]) return;
            if(roots[root->val] != nullptr) {
                root->left = roots[root->val]->left;
                root->right = roots[root->val]->right;
                cnt++;
                visited[root->val] = true;
            }
        }
        dfs(root->left,cnt);
        dfs(root->right,cnt);
    }
    TreeNode* canMerge(vector<TreeNode*>& trees) {
        int n = trees.size();
        for(auto root : trees) {
            if(root->left) parents[root->left->val] = root;
            if(root->right) parents[root->right->val] = root;
            roots[root->val] = root;
        }
        TreeNode* validRoot = nullptr;
        for(auto root : trees) {
            if(parents[root->val] == nullptr) {
                validRoot = root;
                break;
            }
        }
        if(validRoot == nullptr) return nullptr;
        int cnt = 0;
        visited[validRoot->val] = true;
        dfs(validRoot,cnt);
        if(cnt != n-1) return nullptr;
        inorder(validRoot);
        for(int i = 0;i < vals.size()-1;i++) {
            if(vals[i] >= vals[i+1]) return nullptr;
        }
        return validRoot;
    }
};