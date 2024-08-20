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
    ListNode* partition(ListNode* head, int x) {
        if(!head) return nullptr;
        ListNode* temp = head;
        ListNode* last = nullptr;
        ListNode* prev = nullptr;
        if(head->val >= x) {
            prev = last = head;
        }
        else {
            while(temp != nullptr) {
                if(temp->val >= x) {
                    last = temp;
                    break;
                }
                prev = temp;
                temp = temp->next;
            }
        }
        bool headFlag = false;
        ListNode* newHead = nullptr;
        if(last == head) {
            prev = new ListNode(x);
            newHead = prev;
            prev->next = newHead;
            headFlag = true;
        }
        temp = last;
        ListNode* prev2 = last;
        while(temp != nullptr) {
            if(temp->val < x) {
                prev2->next = temp->next;
                prev->next = new ListNode(temp->val);
                prev = prev->next;
                temp = temp->next;
            }
            else {
                prev2 = temp;
                temp = temp->next;
            }
        }
        prev->next = last;
        if(headFlag) return newHead->next;
        return head;
    }
};