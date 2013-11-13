/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
    public:
    void connect(TreeLinkNode *root) {
        if (!root) return;
        TreeLinkNode *p = NULL;
        if (root->left) {
            if (root->right) {
                root->left->next = root->right;
                p = root->right;
            } else {
                p = root->left;
            }
        }
        
        if (root->right) {
            p = root->right;
        }
        
        if (p && root->next) {
            TreeLinkNode *tmp = root->next;
            while (!tmp->left && !tmp->right && tmp->next) tmp = tmp->next;
            if (tmp->left)
            p->next = tmp->left;
            else if (tmp->right)
            p->next = tmp->right;
            else
            p->next = NULL;
        }
        
        connect(root->right);
        connect(root->left);
        
    }
};