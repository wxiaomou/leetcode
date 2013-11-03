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
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        int i_end = inorder.size() - 1;
        int p_end = postorder.size() - 1;
        if (i_end <= -1 || p_end <= -1) return NULL;
        return _build(inorder, 0, i_end, postorder, 0, p_end);
    }
    
    TreeNode * _build(vector<int> &inorder, int i_start, int i_end, vector<int> & postorder, int p_start, int p_end) {
        if (i_start > i_end || p_start > p_end) return NULL;
        TreeNode *root = new TreeNode(postorder[p_end]);
        int index = i_start;
        while (inorder[index] != postorder[p_end]) index++;
        int post_right_len = i_end - index;
        root->left = _build(inorder, i_start, index - 1, postorder, p_start, p_end - post_right_len - 1);
        root->right = _build(inorder, index + 1, i_end, postorder, p_end - post_right_len, p_end - 1);
        return root;
    }
};