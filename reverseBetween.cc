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

	ListNode *reverseBetween(ListNode *head, int m, int n) {
	 if (!head || m >= n) return head;
            ListNode *dummy = new ListNode(0);
            dummy->next = head;
            ListNode *pre = dummy;
            for (int i = 0; i < m - 1; i++) pre = pre->next;
            ListNode *cur = pre->next;
            ListNode *tail = cur, *post = cur->next;
            for (int i = m; i < n; i++) {
                ListNode *tmp = post->next;
                post->next = cur;
                cur = post;
                post = tmp;
            }
            pre->next = cur;
            tail->next = post;
    	return dummy->next; 
    }
    //----------------------------------------------//

	 ListNode *reverseBetween(ListNode *head, int m, int n) {
        if (!head || m >= n) return head;
        ListNode * dummy = new ListNode(0);
        dummy->next = head;
        int cnt = 1;
        ListNode *cur = head;
        ListNode *pre = dummy;
        ListNode *begin = NULL;
        ListNode *post = NULL;
        while (cnt < m) {
            cur = cur->next;
            pre = pre->next;
            cnt++;
        }
        begin = cur;
        post = cur->next;
        while (cnt < n) {
            cnt++;
            ListNode *tmp = post->next;
            post->next = cur;
            cur = post;
            post = tmp;
        }
        pre->next = cur;
        begin->next = post;
        return dummy->next;
    }
	//-----------------------------------------------//
    ListNode *reverseBetween(ListNode *head, int m, int n) {
	   if (m > n)
    			return head;
        if (m == n)
            return head;

			int i = 0;
			int j = 0;
			ListNode *pre = head;
			ListNode *cur = head;

			while (j < n - 1) {
				cur = cur->next;
				j++;
			}

			while (i < m - 2) {
				//cur = cur->next;
				pre = pre->next;
				i++;
				//j++;
			}

			ListNode *right = cur;//->next;
			ListNode *post = right->next;
            ListNode *left;
            if (m > 1)
			    left = pre->next;
            else
                left = head;
                
            cur = left;
			ListNode *tmp = cur->next;
			while (tmp != post) {
				ListNode *tmp1 = tmp;
				tmp = tmp->next;
				tmp1->next = cur;
				cur = tmp1;
			}
            if (m > 1)
			    pre->next = right;
            else
                head = right;
                
			left->next = post;

			return head;
    }
};
/* Add new way
 class Solution {
 public:
 ListNode *reverseBetween(ListNode *head, int m, int n) {
 // Note: The Solution object is instantiated only once and is reused by each test case.
 if (!head) return head;
 if (m == n) return head;
 ListNode *pre = new ListNode(0);
 pre->next = head;
 ListNode *cur = pre;
 head = pre;
 int i = 0;
 while (i < m - 1) {
 i++;
 cur = cur->next;
 }
 
 pre = cur;
 cur = cur->next;
 i++;
 while (cur->next != NULL && i < n) {
 i++;
 ListNode *tmp = cur->next;
 cur->next = tmp->next;
 tmp->next = pre->next;
 pre->next = tmp;
 }
 return head->next;
 }
 };
 
 */
int main(int argc, char **argv) {
	ListNode *head = new ListNode(1);
	//head->next = a;
	ListNode *a = new ListNode(2);
	ListNode *b = new ListNode(3);
	ListNode *c = new ListNode(4);
	ListNode *d = new ListNode(5);

	head->next = a;
	a->next = b;
	b->next = c;
	c->next = d;
	d->next = NULL;
	Solution sol;
	sol.reverseBetween(head, 3, 4);
	return 0;
}
