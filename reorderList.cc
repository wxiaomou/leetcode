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
    //smarter way to handle the odd or even issue.
     void reorderList(ListNode *head) {
        if (!head || !head->next) return; 
        ListNode *pre = head;
        ListNode *post = head;
        stack<ListNode *> s;
        while (post) {
            if (post->next && post->next->next) {
                post = post->next->next;
                pre = pre->next;
            } else {
                break;
            }
        }
        post = pre->next;
        while(post) {
            s.push(post);
            post = post->next;
        }
        pre = head;
        while (s.size()) {
            ListNode *tmp = pre->next;
            ListNode *tmp1 = s.top();
            if (tmp == tmp1) { //if total nodes num is even and now pre is the last one, e.g 1->2->3->4, now tmp == tmp1 == 3, pre is 2
                pre = pre->next;
                break;
            }
            s.pop();
            pre->next = tmp1;
            pre = pre->next;
            pre->next = tmp;
            pre = pre->next;
        }
        pre->next = NULL;
    }
    /*void reorderList(ListNode *head) {
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
    }*/
};