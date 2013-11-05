/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    public:
    bool isBalanced(TreeNode *root) {
        if (!root) return true;
        int left = depth(root->left);
        int right = depth(root->right);
        if (abs(left - right) > 1) return false;
        return isBalanced(root->left) && isBalanced(root->right);
    }
    int depth(TreeNode *root) {
        if (!root) return 0;
        int left = depth(root->left);
        int right = depth(root->right);
        return left > right ? left + 1 : right + 1;
    }
};