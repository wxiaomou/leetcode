/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
public class Solution {
    public int rob(TreeNode root) {
        Pair ret = recur(root);
        return Math.max(ret.pre, ret.prepre);
    }
    private class Pair {
        int prepre;
        int pre;
        Pair() { prepre = 0; pre = 0; }
    }
    public Pair recur(TreeNode root) {
        if (root == null) {
            return new Pair();
        }
        Pair left = recur(root.left);
        Pair right = recur(root.right);
        Pair cur = new Pair();
        cur.pre = root.val + left.prepre + right.prepre;
        cur.prepre = left.pre + right.pre;
        cur.pre = Math.max(cur.pre, cur.prepre);
        return cur;
    }
}
