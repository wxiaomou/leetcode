public class Solution {
    public int findMaximumXOR(int[] nums) {
        if (nums.length == 0) {
            return 0;
        }
        ListNode trie = new ListNode(-1);
        int ret = 0;
        insert(trie, nums[0]);
        for (int i = 1; i < nums.length; i++) {
            ret = Math.max(compute(trie, nums[i]), ret);
            trie = insert(trie, nums[i]);
        }
        return ret;
    }
    
    public class ListNode {
      int val;
      ListNode left;
      ListNode right;
      ListNode(int x) { val = x; }
    }
    
    private ListNode insert(ListNode trie, int num) {
        ListNode cur = trie;
        int tmp = 1 << 30;
        for (int i = 30; i >= 0; i--) {
            if ((tmp & num) > 0) {
                if (cur.right == null) {

                    cur.right = new ListNode(1);
                }
                cur = cur.right;
            } else {
                if (cur.left == null) {
                                                    //System.out.println("" + cur.val + ":" + tmp + ":" + num);

                    cur.left = new ListNode(0);
                }
                cur = cur.left;
            }
            tmp >>= 1;
        }
        return trie;
    }
    
    private int compute(ListNode trie, int num) {
        ListNode cur = trie;
        int ret = 0;
        int tmp = 1 << 30;
        for (int i = 30; i >= 0; i--) {
            if (((tmp) & num) > 0) {
                //  System.out.print("" + i + ":" + num);

                  int add = 0;
                  if (cur.left != null) {
                      cur = cur.left;
                      add = 1;
                  } else {
                      cur = cur.right;
                  }
                  ret <<= 1;
                  ret += add;
            } else {
                int add = 0;
                if (cur.right != null) {
                      cur = cur.right;
                      add = 1;
                  } else {
                      cur = cur.left;
                  }
                  ret <<= 1;
                  ret += add;
            }
            tmp >>= 1;
        }
        return ret;
    }
}
