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
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        vector<vector<int> > ret;
        if (!root) return ret;
        vector<int> tmp;
        _pathSum(root, sum, ret, tmp);
        return ret;
    }
    
    void _pathSum(TreeNode *root, int sum, vector<vector<int> > &ret, vector<int> &tmp) {
        if (!root) return;
        int _sum = sum - root->val;
        tmp.push_back(root->val);
        if (!_sum) {
            if (!root->left && !root->right) {
                ret.push_back(tmp);
                return;
            }
        }
        if (root->left) {
            _pathSum(root->left, _sum, ret, tmp);
            if (tmp.size())
            tmp.pop_back();
        }
        if (root->right) {
            _pathSum(root->right, _sum, ret, tmp);
            if (tmp.size())
            tmp.pop_back();
        }
        return;
    }
};