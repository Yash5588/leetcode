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
    //for storing parents of current node
    unordered_map<int,TreeNode*> parents;
    //for storing tree addresses for that particular root value
    unordered_map<int,TreeNode*> roots;
    //to prevent infinite loop
    //like if one tree is [2,null,3] and other is [3,2,null]
    //then we keep on building them it won't stop
    //so mark them visited
    unordered_map<int,bool> visited;
    bool isLeaf(TreeNode* root) {
        return root->left == nullptr && root->right == nullptr;
    }
    //for sorted array to check if it is bst or not
    vector<int> vals;
    void inorder(TreeNode* root) {
        if(root) {
            inorder(root->left);
            vals.push_back(root->val);
            inorder(root->right);
        }
    }
    //cnt for operations 
    //for suppose some trees are left then we need to return null
    //our aim is to generate only one tree
    void dfs(TreeNode* root, int &cnt) {
        if(root == nullptr) return;
        if(isLeaf(root)) {
            if(visited[root->val]) return;
            if(roots[root->val] != nullptr) {
                //if tree exists for that leaf node
                //then we attach the left and right child to the current node
                //so that tree is built
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
            //store the parents for children
            if(root->left) parents[root->left->val] = root;
            if(root->right) parents[root->right->val] = root;
            //store trees addresses in root values for that trees
            roots[root->val] = root;
        }
        TreeNode* validRoot = nullptr;
        for(auto root : trees) {
            //check a tree such that it's root is not a leaf of any other tree
            if(parents[root->val] == nullptr) {
                validRoot = root;
                break;
            }
        }
        //if not found then null
        if(validRoot == nullptr) return nullptr;
        int cnt = 0;
        visited[validRoot->val] = true;
        dfs(validRoot,cnt);
        //if some trees are left > 2 then null 
        if(cnt != n-1) return nullptr;
        inorder(validRoot);
        //if only tree is formed but it is not bst
        for(int i = 0;i < vals.size()-1;i++) {
            if(vals[i] >= vals[i+1]) return nullptr;
        }
        return validRoot;
    }
};