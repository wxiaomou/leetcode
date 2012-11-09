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
    ListNode *partition(ListNode *head, int x) {
			if (!head || !head->next)
    			return head;

			ListNode *tail = head;
			ListNode *pre = head;
			ListNode *cur = head;
			ListNode *post = cur->next;

			while (cur && cur->val < x) {
				tail = cur;
				cur = cur->next;
			};
			if (!cur)
				return head;

			pre = tail;
			while (cur) {
				print(head);
					post = cur->next;
				if (cur->val < x) {
					//cout << "ref" << endl;
					if (tail->val >= x && head == tail) {
						//cout << "here" << endl;
						ListNode *tmp = tail;
						tail = cur;
						tail->next = tmp;
						cur = post;
						pre->next = cur;
                        head = tail;
					} else {
						ListNode *tmp = tail->next;
						tail->next = cur;
						cur->next = tmp;
						pre->next = post;
						cur = post;
						tail = tail->next;
					}
					//post = cur->next;
				} else {
					pre = cur;
					cur = post;
				}
			}
			return head;
			}
		void print(ListNode *head) {
			while (head) {
				cout << head->val << " ";
				head = head->next;
			}
			cout << endl;
		}
};

int main() {
	Solution sol;
	ListNode *head = new ListNode(1);
	ListNode *tail = new ListNode(3);
	head->next = tail;
	ListNode *a = new ListNode(-1);
	tail->next = a;
	ListNode *b = new ListNode(5);
	a->next = b;
	ListNode *c = new ListNode(2);
	b->next = c;
	ListNode *d = new ListNode(1);
	c->next = d;
	sol.partition(head, 3);
}
