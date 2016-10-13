/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
public class Solution {
    public void reorderList(ListNode head) {
        if (head == null || head.next == null) {
            return;
        }
        ListNode pre = head;
        ListNode post = head;
        while (post != null) {
            post = post.next;
            if (post == null) {
                break;
            }
            pre = pre.next;
            post = post.next;
        }
        post = pre.next;
        pre.next = null;
        post = reverseList(post);
        pre = head;
        while (pre != null && post != null) {
            ListNode cur = post;
            post = post.next;
            ListNode tmp = pre.next;
            pre.next = cur;
            cur.next = tmp;
            pre = tmp;
        }
    }
    private ListNode reverseList(ListNode head) {
        if (head == null) {
            return null;
        }
        ListNode cur = head;
        ListNode post = null;
        ListNode pre = null;
        while(cur != null) {
            post = cur.next;
            cur.next = pre;
            pre = cur;
            cur = post;
        }
        return pre;
    }
}
