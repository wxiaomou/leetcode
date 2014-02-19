/**
 * Definition for singly-linked list.
 */
#include <iostream>
#include <stddef.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode *reverseKGroup(ListNode *head, int k) {
			 if (k <= 1 || !head)
        		return head;

			ListNode *pre = NULL;
			ListNode *cur = head;
			ListNode *post = NULL;

			int i = 0;
			while (i < k && cur) {
				cur = cur->next;
				i++;
			}
			// if left is larger than k;
			if (i < k)
				return head;
			cur = head;
			i = 0;
			while (cur != NULL && i < k) {
				post = cur->next;
				cur->next = pre;
				pre = cur;
				cur = post;
				i++;
			}
			if (post) {
				head->next = reverseKGroup(post, k);
			}

			return pre;
    }


    /*
	 ListNode *reverseKGroup(ListNode *head, int k) {
        if (!k || k == 1 || !head) return head;
        ListNode *pre = head;
        ListNode *cur = head->next;
        int i = 0;
        while (i < k && pre) {
           pre = pre->next;
           i++;
       }
       if (i < k) return head;
       i = 0;
       pre = head;
       ListNode *tail = pre;
       ListNode *post = NULL;
       while (i < k - 1) {
          post = cur->next;
          cur->next = pre;
          pre = cur;
          cur = post;
          i++;
       }
       tail->next = post;
       tail->next = reverseKGroup(post, k);
       
       return pre;
    }
    */

};

int main (int argc, char **argv) {
	return 0;
}
