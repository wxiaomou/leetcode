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
        if (!root) return;
        flatten(root->left);
        TreeNode *left = root->left;
        flatten(root->right);
        TreeNode *right = root->right;
        
        root->left = NULL;
        if (left) {
            root->right = left;
            TreeNode *cur = left;
            while (cur->right) {
                cur = cur->right;
            }
            cur->right = right; 
        } else {
            root->right = right;
        }
        return;
    }
    //---------------------------------------------------------//    
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
        root->left = NULL; //!!!important related to the judge
        TreeNode *ret = root;
        while (root->right) root = root->right;
        root->right = _flat(tmp);
        return ret;
    }
};