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
    public int countNodes(TreeNode root) {
        if (root == null) return 0;
        int lh = getLeft(root);
        int rh = getRight(root);

        if (lh == rh) {
            return (2 << (lh - 1)) - 1;
        }
        return countNodes(root.left) + countNodes(root.right) + 1;
    }
    
    int getLeft(TreeNode root) {
        int count = 0;
        while (root.left != null) {
            count++;
            root = root.left;
        }
        return count + 1;
    }
    
    int getRight(TreeNode root) {
        int count = 0;
        while (root.right != null) {
            count++;
            root = root.right;
        }
        return count + 1;
    } 
}
