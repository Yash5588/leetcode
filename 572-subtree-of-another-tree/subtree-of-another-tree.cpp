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
    void postorder(TreeNode* root, string &str) {
        if(!root) {
            str += '$';
            return;
        }
        postorder(root->left,str);
        postorder(root->right,str);
        str += to_string(root->val);
    }

    void inorder(TreeNode* root, string &str) {
        if(!root) {
            str += '$';
            return;
        }
        inorder(root->left,str);
        str += to_string(root->val);
        inorder(root->right,str);
    }
    vector<int> kmp(string &s, string &pattern) {
        string str = pattern + '#' + s;
        vector<int> lps(str.size(),0);
        for(int i=1;i<str.size();i++) {
            int prev_index = lps[i-1];
            while(prev_index>0 && str[i] != str[prev_index]) {
                prev_index = lps[prev_index-1];
            }
            lps[i] = prev_index + (str[i] == str[prev_index] ? 1 : 0);
        }
        return lps;
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        string s1, pattern1, s2, pattern2;
        inorder(root,s1);
        inorder(subRoot,pattern1);
        postorder(root,s2);
        postorder(subRoot,pattern2);
        vector<int> lps1 = kmp(s1,pattern1);
        vector<int> lps2 = kmp(s2,pattern2);
        bool left = false,right = false;
        for(int i=0;i<lps1.size();i++) {
            if(lps1[i] == pattern1.size())  {
                left = true;
                break;
            }
        }
        for(int i=0;i<lps2.size();i++) {
            if(lps2[i] == pattern2.size()) {
                right = true;
                break;
            }
        }
        return left & right;
    }
};