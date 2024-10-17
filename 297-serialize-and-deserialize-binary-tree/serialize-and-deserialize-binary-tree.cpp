/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s;
        if(!root) return "";
        queue<TreeNode*> que;
        que.push(root);
        s += to_string(root->val);
        while(!que.empty()) {
            TreeNode* node = que.front();
            que.pop();
            if(node->left) {
                que.push(node->left);
                s += ',' + to_string(node->left->val);
            }
            else s += ",#";
            if(node->right) {
                que.push(node->right);
                s += ',' + to_string(node->right->val);
            }
            else s += ",#";
        }
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.empty()) return nullptr;
        int n = data.size();
        int i = 0;
        string str;
        while(i < n && data[i] != ',') {
            str += data[i];
            i++;
        }
        i++;
        queue<TreeNode*> que;
        TreeNode* root = new TreeNode(stoll(str));
        que.push(root);
        while(!que.empty()) {
            TreeNode* node = que.front();
            que.pop();
            string left,right;
            while(i < n && data[i] != ',') {
                left += data[i];
                i++;
            }
            i++;
            while(i < n && data[i] != ',') {
                right += data[i];
                i++;
            }
            i++;
            if(left == "#") node->left = nullptr;
            else {
                node->left = new TreeNode(stoll(left));
                que.push(node->left);
            }
            if(right == "#") node->right = nullptr;
            else {
                node->right = new TreeNode(stoll(right));
                que.push(node->right);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));