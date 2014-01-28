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
        if (!root) return vector<vector<int>>();
        if (!root->left && !root->right && root->val == sum) {
            return vector<vector<int>> (1, vector<int>(1, sum));
        }
        vector<vector<int>> left;
        vector<vector<int>> right;
        vector<vector<int>> ret;
        if (root->left) left = pathSum(root->left, sum - root->val); 
        if (root->right) right = pathSum(root->right, sum - root->val);
        for (int i = 0; i < left.size(); i++) left[i].insert(left[i].begin(), root->val);
        for (int i = 0; i < right.size(); i++) right[i].insert(right[i].begin(), root->val);
        if (left.size()) ret.insert(ret.end(), left.begin(), left.end());
        if (right.size()) ret.insert(ret.end(), right.begin(), right.end());
        return ret;
    }
    //-----------------------------------------------------------//    
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