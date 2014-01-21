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
     bool hasCycle(ListNode *head) {
        if (!head) return false;
        ListNode *first = head;
        ListNode *second = head;
        while (second->next && second->next->next) {
            first = first->next;
            second = second->next->next; 
            if (first == second) return true;
        }
        return false;
    }
    //------------------------------------------//
    bool hasCycle(ListNode *head) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if (!head) return false;
        ListNode *a = head;
        ListNode *b = head->next;
        while (a && b) {
            if (a == b) return true;
            a = a->next;
            if (b->next)
                b = b->next->next;
            else 
                break;
        }
        return false;
    }
};