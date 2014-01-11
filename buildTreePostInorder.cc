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

    //-----------------------------------------------------------------//
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        int n = inorder.size();
        if (!n) return NULL;
        return build(postorder, 0, n - 1, inorder, 0, n - 1);
    }
    
    TreeNode *build(vector<int> &postorder, int p_b, int p_e, vector<int> &inorder, int i_b, int i_e) {
        if (p_b > p_e) return NULL;
        TreeNode *root = new TreeNode(postorder[p_e]);
        if (p_b == p_e) return root;
        int len = 0;
        
        for (int i = i_b; i <= i_e; ++i) {
            if (inorder[i] == postorder[p_e]) break;
            len++;
        }
        root->right = build(postorder, p_b + len, p_e - 1, inorder, i_b + len + 1, i_e);
        root->left = build(postorder, p_b, p_b + len - 1, inorder, i_b, i_b + len - 1);
    }


    /*
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        if (!inorder.size()) return NULL;
        if (inorder.size() != postorder.size()) return NULL;
        return _build(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1);
    }
    
    TreeNode *_build(vector<int> &inorder, int start, int end, vector<int> &postorder, int start2, int end2) {
        if (start > end) return NULL;
        if (start2 == end2) 
            return new TreeNode(postorder[start2]);
        TreeNode *root = new TreeNode(postorder[end2]);
        int i = 0;
        while (end - i >= start) {
            if (postorder[end2] == inorder[end - i])
                break;
            i++;
        }
        root->left = _build(inorder, start, end - i - 1, postorder, start2, end2 - i - 1);
        root->right = _build(inorder, end - i + 1, end, postorder, end2 - i, end2 - 1);
    }*/
};