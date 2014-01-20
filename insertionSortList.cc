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
    ListNode *insertionSortList(ListNode *head) {
        if (!head) return NULL;
        if (!head->next) return head;
        ListNode *dummy = new ListNode(INT_MIN);
        dummy->next = head;
        head = dummy;
        ListNode *cur = head;
        while (cur && cur->next) {
            ListNode *first = head;
            ListNode *second = head->next;
            ListNode *tmp = cur->next;
            while (second != cur->next && tmp->val >= second->val) {
                first = second;
                second = second->next;
            }
            if (!(!second || second == cur->next)) {
                cur->next = tmp->next;
                first->next = tmp;
                tmp->next = second;
            } else {
                cur = cur->next;
            }
            
        }
        head = head->next;
    }
    //----------------------------------------------//
     ListNode *insertionSortList(ListNode *head) {
        if (!head) return NULL;
        ListNode *ret = head;
        ListNode *cur = head->next;
        ret->next = NULL;
        while (cur) {
            if (ret->val >= cur->val) {
                ListNode *tmp = cur->next;
                cur->next = ret;
                ret = cur;
                cur = tmp;
            } else {
                ListNode *cur1 = ret;
                while (cur1->next) {
                    if (cur1->next->val > cur->val) {
                        ListNode *tmp = cur1->next;
                        ListNode *tmp1 = cur->next;
                        cur1->next = cur;
                        cur->next = tmp;
                        cur = tmp1;
                        break;
                    } 
                    cur1 = cur1->next;
                }
                if (!cur1->next) {
                    cur1->next = cur;
                    cur = cur->next;
                    cur1->next->next = NULL;
                }
            }
        }
        return ret;
    }
};