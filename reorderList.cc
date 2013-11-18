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
    void reorderList(ListNode *head) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if (!head || !head->next || !head->next->next) return;
        ListNode *first = head;
        ListNode *second = head;
        stack<ListNode *> s;
        bool odd = false;
        while (second) {
            s.push(first);
            first = first->next;
            if (second) {
                second = second->next;
                odd = true;
            }
            if (second) {
                second = second->next;
                odd =false;
            }
        }
        ListNode *ret = NULL;
        if (odd) {
            ret = s.top();
            s.pop();
            ret->next = NULL;
        }
        ListNode *tmp = first->next;
        while (s.size() ) {
            first->next = ret;
            ret = first;
            s.top()->next = ret;
            ret = s.top();
            s.pop();
            if (tmp) {
                first = tmp;
                tmp = tmp->next;
            } 
        }
        head = ret;        
    }
};