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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head) return nullptr;
        ListNode* last = head;
        int size = 0;
        while(last->next) {
            last = last->next;
            size++;
        }
        size++;
        k %= size;
        for(int i=0;i<size-k;i++) {
            last->next = new ListNode(head->val);
            last = last->next;
            head = head->next;
        }
        return head;
    }
};