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
        ListNode* small = nullptr;
        ListNode* large = nullptr;
        ListNode* largeHead = nullptr;
        ListNode* smallHead = nullptr;
        while(head != nullptr) {
            if(head->val < x) {
                if(smallHead == nullptr) {
                    small = smallHead = head;
                }
                else {
                    small->next = head;
                    small = small->next;
                }
            }
            else {
                if(largeHead == nullptr) {
                    large = largeHead = head;
                }
                else {
                    large->next = head;
                    large = large->next;
                }
            }
            head = head->next;
        }
        if(smallHead == nullptr) {
            large->next = nullptr;
            return largeHead;
        }
        if(largeHead == nullptr) {
            small->next = nullptr;
            return smallHead;
        }
        small->next = largeHead;
        large->next = nullptr;
        return smallHead;
    }
};