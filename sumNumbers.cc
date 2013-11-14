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
        _sumNumbers(root, ref, 0);
        for (int i = 0; i < ref.size(); i++) ret += ref[i];
        return ret;
    }
    
    void _sumNumbers(TreeNode *root, vector<int> &ref, int pre) {
       if (!root) return;
       pre *= 10;
       pre += root->val;
       if (!root->left && !root->right) {
           ref.push_back(pre);
           return;
       }
       if (root->left) _sumNumbers(root->left, ref, pre);
       if (root->right) _sumNumbers(root->right, ref, pre);
       return;
    }
};