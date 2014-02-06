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
        if (!l1) return l2;
        if (!l2) return l1;
        ListNode *head = NULL, *cur;
        while (l1 && l2) {
            if (l1->val < l2->val) {
                if (!head) {
                    head = l1;
                    cur = l1;
                } else {
                    cur->next = l1;
                    cur = cur->next;
                }
                l1 = l1->next;
            } else {
                if (!head) {
                    head = l2;
                    cur = l2;
                } else {
                    cur->next = l2;
                    cur = cur->next;
                }
                l2 = l2->next;
            }
            cur->next = NULL;
        }
        if (l1) cur->next = l1;
        if (l2) cur->next = l2;
        return head;
    }
    //-------------------------------------------//
	ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        if (!l1) return l2;
        if (!l2) return l1;
        ListNode *cur1 = NULL;
        ListNode *cur2 = NULL;
        ListNode *cur = NULL;
        ListNode * head = NULL;
        
        if (l1->val > l2->val) {
            cur1 = l2;
            cur2 = l1;
        } else {
            cur1 = l1;
            cur2 = l2;
        }
        cur = cur1;
        head = cur1;
        
        while (cur1 && cur2) {
            if (cur1->val > cur2->val) {
                ListNode *tmp = cur2->next;
                cur->next = cur2;
                cur = cur->next;
                cur->next = NULL;
                cur2 = tmp;
            } else {
                ListNode *tmp = cur1->next;
                cur->next = cur1;
                cur = cur->next;
                cur->next = NULL;
                cur1 = tmp;
            }
        }
        if (cur1) {
            cur->next = cur1;
        } else if (cur2) {
            cur->next = cur2;
        }
        return head;
    }

    /*ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
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
    }*/
};

int main(int argc, char **argv) {
	return 0;
}
