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
    void flatten(TreeNode *root) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if (!root) return;
        _flat(root);
    }
    
    TreeNode *_flat(TreeNode *root) {
        if (!root) return NULL;
        TreeNode *tmp = root->right;
        root->right = _flat(root->left);
        root->left = NULL;
        TreeNode *ret = root;
        while (root->right) root = root->right;
        root->right = _flat(tmp);
        return ret;
    }
};