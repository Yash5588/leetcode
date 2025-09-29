/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */

class Solution {
    static ListNode reverse(ListNode head) {
        if(head==null) return null;
            ListNode curr=head;
            ListNode prev=null;
        ListNode nn=null;
        while(curr!=null)
        {
            nn=curr.next;
            curr.next=prev;
            prev=curr;
            curr=nn;

        }
        
        return prev;
    }
    public void reorderList(ListNode head) {
        int size = 0;
        ListNode temp = head;
        while(temp != null) {
            size++;
            temp = temp.next;
        }
        temp = head;
        int last = size/2;
        if(size % 2 == 0) last--; 
        int cnt = 0;  
        ListNode nextHead = null;      
        while(cnt <= last) {
            if(cnt == last) {
                nextHead = temp.next;
                temp.next = null;
            }
            cnt++;
            temp = temp.next;
        }
        nextHead = reverse(nextHead);
        cnt = 0;
        temp = head;
        ListNode temp2 = nextHead;
        while(temp.next != null) {
            ListNode tempNext = temp.next;
            ListNode temp2Next = temp2.next;
            temp.next = temp2;
            temp = tempNext;
            temp2.next = temp;
            temp2 = temp2Next;
        }
        if(size % 2 == 0) temp.next = temp2;
    }
}