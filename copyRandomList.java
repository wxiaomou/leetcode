/**
 * Definition for singly-linked list with a random pointer.
 * class RandomListNode {
 *     int label;
 *     RandomListNode next, random;
 *     RandomListNode(int x) { this.label = x; }
 * };
 */
public class Solution {
    public RandomListNode copyRandomList(RandomListNode head) {
        if (head == null) {
            return head;
        }
        RandomListNode ret = null, cur2 = null;
        RandomListNode cur = head;
        while (cur != null) {
            RandomListNode tmp = cur.next;
            cur.next = new RandomListNode(cur.label);
            cur.next.next = tmp;
            cur = tmp;
        }
        cur = head;
        cur2 = cur.next;
        while (cur != null) {
            if (cur.random != null) {
                cur2.random = cur.random.next;
            }
            cur = cur2.next;
            if (cur != null) {
                cur2 = cur.next;
            }
        }
        cur = head;
        cur2 = cur.next;
        while (cur != null) {
            if (ret == null) {
                ret = cur2;
            }
            cur.next = cur2.next;
            cur = cur.next;
            if (cur != null) {
                cur2.next = cur.next;
                cur2 = cur2.next;
            }
        }
        return ret;
    }
}
