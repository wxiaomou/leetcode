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
    
    int maxPathSum(TreeNode *root) {
        if (!root) return 0;
        int ret = INT_MIN;
        _max(root, ret);
        return ret;
    }
    
    int _max(TreeNode *root, int &ret) {
        if (!root) return 0;
        int left = _max(root->left, ret);
        int right = _max(root->right, ret);
        if (root->val > ret) ret = root->val;
        if (left + root->val > ret) ret = left + root->val;
        if (root->val + right > ret) ret = root->val + right;
        if (left + root->val + right > ret) ret = left + root->val + right;
        return max(root->val, max(left + root->val, root->val + right));
    }
};