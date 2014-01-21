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
    vector<int> preorderTraversal(TreeNode *root) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        vector<int> ret;
        if (!root) return ret;
        stack<TreeNode *> s;
        s.push(root);
        while (s.size()) {
            TreeNode *tmp = s.top();
            ret.push_back(tmp->val);
            s.pop();
            if (tmp->right) s.push(tmp->right);
            if (tmp->left) s.push(tmp->left);
        }   
        return ret;
    }
};