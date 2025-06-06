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
    public ListNode swapPairs(ListNode head) {
        ListNode dummy = new ListNode(0);
        dummy.next = head;
    
        ListNode pointer = dummy;
        while(pointer.next != null && pointer.next.next != null) {
            ListNode first = pointer.next;
            ListNode second = pointer.next.next;
            System.out.println(first.val + " " + second.val);
            
            first.next = second.next;
            second.next = first;
            pointer.next= second;

            pointer = pointer.next.next;
        }

        return dummy.next;
    }
}
