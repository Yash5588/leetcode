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
        //count each occurance and point last pointer at last occurance
        while(last != nullptr) {
            int count = 1;
            while(last->next != nullptr && last->val == last->next->val) {
                count++;
                last = last->next;
            }
            //if count of that occurance is 1 then only we will assign
            //last to first otherwise ignore those nodes
            if(count == 1) {
                first->val = last->val;
                first = first->next;
            }
            last = last->next;
        }
        //edge case when list is [1,1,2,2] no node has 1 occurance
        //then basically remove whole list
        if(first == head) return nullptr;

        //shrink the list for that we need to remove list from where first is pointing
        ListNode* temp = head;
        while(temp->next != first) {
            temp = temp->next;
        }
        //make the node which is pointed by first pointer as NULL
        temp->next = nullptr;
        return head;
    }
};