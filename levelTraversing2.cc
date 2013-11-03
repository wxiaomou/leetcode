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
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        vector<vector<int> > ret;
        if (!root) return ret;
        queue<TreeNode *> q;
        int cnt = 0;
        vector<int> *l = new vector<int>();
        cnt = 1;
        q.push(root);
        while (q.size()) {
            TreeNode * tmp = q.front();
            q.pop();
            l->push_back(tmp->val);
            if (tmp->left)
            q.push(tmp->left);
            if (tmp->right)
            q.push(tmp->right);
            cnt--;
            if (!cnt) {
                cnt = q.size();
                ret.insert(ret.begin(), *l);
                l = new vector<int>;
            }
        }
        return ret;
    }
};