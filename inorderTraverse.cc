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
    vector<int> inorderTraversal(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> res;
        if (!root) { 
            return res;
        }
        
        if (root->left) {
            res = inorderTraversal(root->left);
        }
        
        res.push_back(root->val);
        
        if (root->right) {
            vector<int> tmp = inorderTraversal(root->right);
            res.insert( res.end(), tmp.begin(), tmp.end() );
        }
        
        return res;
                                    
    }
};
