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
    TreeNode* root = nullptr;
    void preorder(int targetDepth, int node, TreeNode* root, int depth) {
        if(root) {
            //check if we reach destination
            if(depth + 1 == targetDepth) {
                //if left node not preset insert it at left
                if(root->left == nullptr) {
                    root->left = new TreeNode(node);
                }
                //otherwise insert at right side
                else {
                    root->right = new TreeNode(node);
                }
                return;
            }
            //move to right if present
            if(root->right) {
                preorder(targetDepth, node, root->right, depth + 1);
            }
            //else move to left
            else {
                preorder(targetDepth, node, root->left, depth + 1);
            }
        }
    }
    void buildTree(vector<pair<int,int>> pairs) {
        int n = pairs.size();
        //build tree according to mentioned in question
        root = new TreeNode(pairs[0].second);
        for(int i = 1;i < n;i++) {
            preorder(pairs[i].first,pairs[i].second,root,0);
        }
    }
    TreeNode* recoverFromPreorder(string str) {
        //form as pairs for easy access
        //first -> depth
        //second -> node val
        vector<pair<int,int>> pairs;
        int n = str.length(),i = 0;
        while(i < n) {
            int depth = 0;
            string node;
            while(i < n && str[i] == '-') {
                depth++;
                i++;
            }
            while(i < n && str[i] != '-') {
                node += str[i];
                i++;
            }
            pairs.push_back({depth,stoll(node)});
        }
        buildTree(pairs);
        return root;
    }
};