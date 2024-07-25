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
// this is divide and conquer
    // TreeNode* createTree(vector<int> &a, int first, int last) {
    //     if(first > last) return nullptr;
    //     int i = max_element(a.begin()+first,a.begin()+last+1) - a.begin();
    //     TreeNode* root = new TreeNode(a[i]);
    //     root->left = createTree(a,first,i-1);
    //     root->right = createTree(a,i+1,last);
    //     return root;
    // }
    TreeNode* constructMaximumBinaryTree(vector<int>& a) {
        int n = a.size();
        // this is monotonic decreaing stack 
        stack<TreeNode*> sta;
        for(int i=0;i<n;i++) {
            TreeNode* node = new TreeNode(a[i]);
            TreeNode* prev = nullptr;
            while(!sta.empty() && sta.top()->val <= a[i]) {
                prev = sta.top();
                sta.pop();
            }
            node->left = prev;
            if(!sta.empty()) sta.top()->right = node; 
            sta.push(node);
        }
        while(sta.size() != 1) {
            sta.pop();
        }
        return sta.top();
    }
};