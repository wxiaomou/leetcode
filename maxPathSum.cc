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
     int ret;
    int maxPathSum(TreeNode *root) {
        if (!root) return 0;
        ret = INT_MIN;
        recur(root);
        return ret;
    }
    
    int recur(TreeNode *root) {
        if (!root) return -1000;
        if (!root->left && !root->right) {
            ret = max(ret, root->val);   
            return root->val;
        }
        int left = recur(root->left);
        int right = recur(root->right);
        if (root->left && root->right) {
            int tmp = max(left, right);
            ret = max(ret, max(root->val, max(root->val + tmp, root->val + right + left) ) );
            return max(root->val, root->val + max(left, right));
        } else {
            int tmp = root->left ? left : right;
            ret = max(ret, max(root->val, root->val + tmp) );
            return max(root->val, root->val + tmp);
        }
    }
}
//--------------------------------------------//
class Solution {
public:
    int ret;
    int maxPathSum(TreeNode *root) {
        if (!root) return 0;
        ret = INT_MIN;
        _maxPathSum(root);
        return ret;
    }
    int _maxPathSum(TreeNode *root) {
        if (!root) return 0;
        int r = _maxPathSum(root->right);
        ret = max( max( max( max(l + root->val, r + root->val), l + r + root->val), root->val), ret); // need add root->val to l and r, cause {-3}, 
        //if max(max(l,r) ....) ir will return 0 not -1, so let the comparion of l, r and ret into the recursion of node (root->left and root->right)
        // i.e. each level need to add root->val, so in this level do not need to compare l and r. if !root return INT_MIN then sometimes may cause overflow
        return max(root->val, root->val + max(l, r));
    }
};

 //-----------------------------------------------//
class Solution {
public:
    int maxPathSum(TreeNode *root) {
        if (!root) return 0;
        int ret = INT_MIN;
        _max(root, ret);
        return ret;
    }
    
    int _max(TreeNode *root, int &ret) {
        if (!root) return 0;
        int left = _max(root->left, ret);
        int right = _max(root->right, ret);
        if (root->val > ret) ret = root->val;
        if (left + root->val > ret) ret = left + root->val;
        if (root->val + right > ret) ret = root->val + right;
        if (left + root->val + right > ret) ret = left + root->val + right;
        return max(root->val, max(left + root->val, root->val + right));
    }
};