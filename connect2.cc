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
        TreeLinkNode *cur = root->next;
        while (cur) {
            if (cur->left) {
                p = cur->left;
                break;
            } else if (cur->right) {
                p = cur->right;
                break;
            }
            cur = cur->next;
        }
        if (root->left) {
            if (root->right)
                root->left->next = root->right;
            else {
                root->left->next = p;
            }
        }
        if (root->right) {
            root->right->next = p;
        }
        connect (root->right); //right first
        connect (root->left);
    }

    /*    
    void connect(TreeLinkNode *root) {
        if (!root) return;
        TreeLinkNode *p = NULL;;
        if (root->left) {
            if (root->right) {
                root->left->next = root->right;
            } else {
                p = root->left;
            }
        }
        if (root->right) p = root->right;
        if (p) {
            TreeLinkNode *cur = root->next;
            p->next = NULL;
            while (cur) {
                if (cur->left) {
                    p->next = cur->left;
                    break;
                } else if (cur->right) {
                    p->next = cur->right;
                    break;
                }
                cur = cur->next;
            }
        }
        connect(root->right);
        connect(root->left);
    }
    */
};