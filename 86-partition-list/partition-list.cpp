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
        //simple two pointer approach create smaller and larger lists
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
        //if no small list make large list as main list
        if(smallHead == nullptr) {
            large->next = nullptr;
            return largeHead;
        }
        //if no large list make small list as main list
        if(largeHead == nullptr) {
            small->next = nullptr;
            return smallHead;
        }
        //if both lists present then merge both lists
        small->next = largeHead;
        large->next = nullptr;
        return smallHead;
    }
};