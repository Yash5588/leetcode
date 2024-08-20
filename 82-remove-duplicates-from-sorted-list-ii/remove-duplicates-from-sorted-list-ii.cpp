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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == nullptr) return nullptr;
        ListNode* first = head;
        ListNode* last = head;
        while(last != nullptr) {
            int count = 1;
            while(last->next != nullptr && last->val == last->next->val) {
                count++;
                last = last->next;
            }
            if(count == 1) {
                first->val = last->val;
                first = first->next;
            }
            last = last->next;
        }
        if(first == head) return nullptr;
        ListNode* temp = head;
        while(temp->next != first) {
            temp = temp->next;
        }
        temp->next = nullptr;
        return head;
    }
};