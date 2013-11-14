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
    int sumNumbers(TreeNode *root) {
        if (!root) return 0;
        vector<int> ref;
        int ret = 0;
        _sumNumbers(root, ret, 0);
        return ret;
    }
    
    void _sumNumbers(TreeNode *root, int &ret, int pre) {
       if (!root) return;
       pre *= 10;
       pre += root->val;
       if (!root->left && !root->right) {
            ret += pre;
            return;
       }
       if (root->left) _sumNumbers(root->left, ret, pre);
       if (root->right) _sumNumbers(root->right, ret, pre);
       return;
    }
};