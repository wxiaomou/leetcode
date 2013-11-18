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
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
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
};