/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    TreeNode* createTree(vector<int> &inorder,int start,int end) {
        if(start > end) return nullptr;
        TreeNode* root = nullptr;
        int ind = (start + end)/2;
        int ele = inorder[ind];
        root = new TreeNode(ele);
        root->left = createTree(inorder, start, ind-1);
        root->right = createTree(inorder, ind+1, end);
        return root;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int> inorder;
        ListNode* temp = head;
        while(temp != nullptr) {
            inorder.push_back(temp->val);
            temp = temp->next;
        }
        int n = inorder.size();
        return createTree(inorder,0,n-1);
    }
};