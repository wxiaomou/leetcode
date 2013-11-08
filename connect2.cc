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
        if (root->left) {
            if (root->right)
            root->left->next = root->right;
            else if (root->next){
                //root->left->next = root->next->left ? root->next->left : root->next->right;
                TreeLinkNode *tmp = root->next;
                while (!tmp->left && !tmp->right && tmp->next) tmp = tmp->next;
                if (tmp->left)
                root->left->next = tmp->left;
                else if (tmp->right)
                root->left->next = tmp->right;
                else
                root->left->next = NULL;
            }
        }
        if (root->right) {
            if (root->next) {
                TreeLinkNode *tmp = root->next;
                while (!tmp->left && !tmp->right && tmp->next) tmp = tmp->next;
                if (tmp->left)
                root->right->next = tmp->left;
                else if (tmp->right)
                root->right->next = tmp->right;
                else
                root->right->next = NULL;
            }
        }
        connect(root->right);
        connect(root->left);
        
    }
};