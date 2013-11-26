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
    ListNode *detectCycle(ListNode *head) {
        if (!head) return NULL;
        ListNode *pre = head;
        ListNode *post = head;
        do {
            pre = pre->next;
            if (!post || !post->next)
                return NULL;
            post = post->next->next;
        } while (pre != post);
        
        pre = head;
        while (pre != post) {
            pre = pre->next;
            post = post->next;
        }
        return pre;
    }
};