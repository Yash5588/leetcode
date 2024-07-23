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
    vector<int> zfunc(string &s, string pattern) {
        string str = pattern + '#' + s;
        vector<int> z(str.size(),0);
        int left = 0,right = 0;
        for(int i=1;i<str.size();i++) {
            if(i > right) {
                left = right = i;
                while(right < str.size() && str[right] == str[right-left]) {
                    right++;
                }
                z[i] = right - left;
                right--;
            }
            else {
                int ind = i - left;
                if(i + z[ind] <= right) {
                    z[i] = z[ind];
                }
                else {
                    left = i;
                    while(right < str.size() && str[right] == str[right-left]) {
                        right++;
                    }
                    z[i] = right-left;
                    right--;
                }
            }
        }
        return z;
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        string s1, pattern1, s2, pattern2;
        inorder(root,s1);
        inorder(subRoot,pattern1);
        postorder(root,s2);
        postorder(subRoot,pattern2);
        vector<int> z1 = zfunc(s1,pattern1);
        vector<int> z2 = zfunc(s2,pattern2);
        bool left = false, right = false;
        for(auto &x : z1) {
            if(x == pattern1.size()) {
                left = true;
                break;
            }
        }
        for(auto &x : z2) {
            if(x == pattern2.size()) {
                right = true;
                break;
            }
        }
        return right & left;
    }
};