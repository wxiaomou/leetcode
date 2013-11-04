/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    TreeNode *sortedListToBST(ListNode *head) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if (!head) return NULL;
        int len = 0;
        ListNode *it = head;
        while (it) {
            it = it->next;
            len++;
        }
        return _build(head, len);
    }
    
    TreeNode *_build(ListNode *head, const int len) {
        if (!head) return NULL;
        if (len == 0) return NULL;
        if (len == 1) return new TreeNode(head->val);
        int tmp = 0;
        if (len % 2)
        tmp = len / 2;
        else
        tmp = len / 2 - 1;
        ListNode *it = head;
        for (int i = 0; i < tmp; i++) it = it->next;
        TreeNode *root = new TreeNode(it->val);
        root->left = _build(head, tmp);
        root->right = _build(it->next, len - tmp - 1);
        return root;
    }
};