/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        unordered_set<ListNode*> se;
        ListNode* temp = head;
        while(temp != nullptr) {
            if(se.count(temp)) {
                return temp;
            } 
            se.insert(temp);
            temp = temp->next;
        }
        return nullptr;
    }
};