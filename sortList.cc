/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *sortList(ListNode *head) {
        if (!head) return NULL;
        if (!head->next) return head;
        ListNode * pivot = head;
        ListNode * left = NULL;
        ListNode * right = NULL;
        ListNode * cur = head->next;
        ListNode * left_cur = NULL;
        ListNode * right_cur = NULL;
        bool _left = false;
        bool _right = false;
        while (cur) {
            if (cur->val < pivot->val) {
                if (!left) {
                    left = cur;
                    left_cur = cur;
                } else {
                    left_cur->next = cur;
                    if (cur->val < left_cur->val) _left = true;
                    left_cur = left_cur->next;
                }
            } else {
                if (!right) {
                    right = cur;
                    right_cur = cur;
                } else {
                    right_cur->next = cur;
                    if (cur->val < right_cur->val) _right = true;
                    right_cur = right_cur->next;
                }
            }
            cur = cur->next;
        }

        
        if (left_cur)
            left_cur->next = NULL;
        if (right_cur)
            right_cur->next = NULL;
            
        if (_left)
            head = sortList(left);
        else
            head = left;
        cur = head;
        if (cur) {
            while (cur->next) cur = cur->next;
            cur->next = pivot;
        } else {
            head = pivot;
        }
        if (_right)
            pivot->next = sortList(right);
        else
            pivot->next = right;
            
        return head;
    }
};
