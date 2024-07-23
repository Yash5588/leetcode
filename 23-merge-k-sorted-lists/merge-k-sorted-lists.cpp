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
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<int,vector<int>,greater<>> que;
        for(auto node : lists) {
            ListNode* temp = node;
            while(temp) {
                que.push(temp->val);
                temp = temp->next;
            }
        }
        ListNode* head = nullptr;
        ListNode* last = nullptr;
        while(!que.empty()) {
            int val = que.top();
            que.pop();
            if(!head) {
                head = last = new ListNode(val);
            }
            else {
                last->next = new ListNode(val);
                last = last->next;
            }
        }
        return head;
    }
};