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
    public ListNode mergeKLists(ListNode[] lists) {
        if (lists == null || lists.length == 0) return null;

        ListNode dummy = new ListNode(0);
        ListNode pointer = dummy;

        PriorityQueue<ListNode> pq = new PriorityQueue<>(Comparator.comparingInt(node -> node.val));
        for (ListNode node : lists) {
            if (node != null) {
                pq.offer(node);
            }
        }

        while(pq.isEmpty() == false) {
            ListNode cur = pq.poll();
            pointer.next = cur;
            pointer = pointer.next;
            cur = cur.next;
            if (cur != null) {
                pq.offer(cur);
            }
        }

        return dummy.next;
    }
}
