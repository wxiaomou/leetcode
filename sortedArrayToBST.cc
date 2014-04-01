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
    TreeNode *sortedArrayToBST(vector<int> &num) {
        int len = num.size();
        if (!len) return NULL;
        return _build(num, 0, num.size() - 1);
    }
    
    
    TreeNode *_build(vector<int> &num, int begin, int end) {
        if (begin > end) return NULL;
        TreeNode *root = new TreeNode(num[(end + begin) / 2]);
        root->left = _build(num, begin, ((end + begin) / 2) - 1);
        root->right = _build(num, ((end + begin) / 2) + 1, end);
        return root;
    }
    
};