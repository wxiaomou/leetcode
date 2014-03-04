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
        ListNode *pre = head, *cur = head;
        while (cur) {
            if (cur->next)
                cur = cur->next->next;
            else 
                break;
            if (!cur) break;
            pre = pre->next;
        }
        ListNode *post = sortList(pre->next);
        pre->next = NULL;
        pre = sortList(head);
        head = NULL;
        cur = NULL;
        while (pre && post) {
            if (pre->val < post->val) {
                if (!head) {
                    head = pre;
                    cur = head;
                } else {
                    cur->next = pre;
                    cur = cur->next;
                }
                pre = pre->next;
            } else {
                if (!head) {
                    head = post;
                    cur = head;
                } else {
                    cur->next = post;
                    cur = cur->next;
                }
                post = post->next;
            }
        }
        if (pre || post) {
            if (cur)
                cur->next = pre ? pre : post;
            else 
                return pre ? pre : post;
        }
        return head;
    }
    //------------------------------//
    ListNode *sortList(ListNode *head) {
        if (!head) return head;
        int pivot = head->val;
        ListNode *cur = head->next;
        head->next = NULL; //!!!!!!!!!!!!!!O.W. will have loop
        ListNode *left = NULL, *left_cur = NULL, *right = NULL, *right_cur = NULL;
        bool doLeft = false, doRight = false;
        
        while (cur) {
            if (cur->val <= pivot) {
                if (!left) {
                    left = cur;
                    left_cur = left;
                } else {
                    if (left_cur->val > cur->val) doLeft = true;
                    left_cur->next = cur;
                    left_cur = left_cur->next;
                }
            } else {
                if (!right) {
                    right = cur;
                    right_cur = right;
                } else {
                    if (right_cur->val > cur->val) doRight = true;
                    right_cur->next = cur;
                    right_cur = right_cur->next;
                }
            }
            cur = cur->next;
        }
        
        ListNode *ret = head;
        if (left) {
            left_cur->next = NULL;
            ret = doLeft ? sortList(left) : left;
            cur = ret;
            while(cur->next) cur = cur->next;
            cur->next = head;
        }
        if (right) {
            right_cur->next = NULL;
            head->next = doRight ? sortList(right) : right;
        }
        return ret;
    }
    //-------------------------------------------//
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
                    if (cur->val < left_cur->val) _left = true; //4->1->2->3->5->6->7 we don't want resort 1->2->3 and 4->5->6 so that I add these two flag of _left and _right.
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
            left_cur->next = NULL; //!!!no matter we recurse it or not, the sublist should end with NULL.
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
