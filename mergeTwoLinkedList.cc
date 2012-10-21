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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
			if (!l1 || !l2) {
				return l1 ? l1 : l2;
			}
			ListNode *res = NULL;
			ListNode *tail = NULL;
			while (l1 && l2) {
				if (l1->val < l2->val)  {
					ListNode *tmp = new ListNode(l1->val);
					if (!res) {
						res = tmp;
						tail = res;
					} else {
						tail->next = tmp;
						tail = tail->next;
					}
					l1 = l1->next;
				} else {
					ListNode *tmp = new ListNode(l2->val);
					if (!res) {
						res = tmp;
						tail = res;
					} else {
						tail->next = tmp;
						tail = tail->next;
					}
					l2 = l2->next;
				}
			}

			ListNode *p = l1 ? l1 : l2;
			while (p) {
				ListNode *tmp = new ListNode(p->val);
				tail->next = tmp;
				tail = tail->next;
				p = p->next;
			}
			return res;
    }
};

int main(int argc, char **argv) {
	return 0;
}
