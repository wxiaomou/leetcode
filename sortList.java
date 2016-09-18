/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
public class Solution {
    public ListNode sortList(ListNode head) {
        if (head == null) {
            return null;
        }
        int len = 1;
        ListNode p = head;
        while (p != null) {
            p = p.next;
            len++;
        }
        ListNode fakehead = new ListNode(-1);
        fakehead.next = head;
        for (int interval = 1; interval <= len; interval *= 2) {
            ListNode pre = fakehead;
            ListNode slow = fakehead.next;
            ListNode fast = fakehead.next;
            while (slow != null || fast != null) {
                //System.out.println(pre.val);
                // move fast to its start point
                int svisit = 0;
                int fvisit = 0;
                for (int i = 0; i < interval && fast != null; i++) {
                    fast = fast.next;
                }
                while (svisit < interval && fvisit < interval && slow != null && fast != null) {
                    if (slow.val < fast.val) {
                        pre.next = slow;
                        svisit++;
                        pre = pre.next;
                        slow = slow.next;
                    } else {
                        pre.next = fast;
                        fvisit++;
                        pre = pre.next;
                        fast = fast.next;                        
                    }
                }
                while (svisit < interval && slow != null) {
                        pre.next = slow;
                        svisit++;
                        pre = pre.next;
                        slow = slow.next;
                }
                while (fvisit < interval && fast != null) {
                        pre.next = fast;
                        fvisit++;
                        pre = pre.next;
                        fast = fast.next; 
                }
                pre.next = fast;
                slow = fast;
            }
        }
        return fakehead.next;
    }
}
