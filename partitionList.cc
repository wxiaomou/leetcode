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
        if (!head) return head;
        ListNode *left = NULL, *right = NULL, *right_s = NULL, *cur = head;
        while (cur) {
            if (cur->val < x) {
                if (!left) {
                    left = cur;
                    head = left;
                } else {
                    left->next = cur;
                    left = left->next;
                }
            } else {
                if (!right) {
                    right = cur;
                    right_s = cur;
                } else {
                    right->next = cur;
                    right = right->next;
                }
            }
            ListNode *tmp = cur->next;
            cur->next = NULL;
            cur = tmp;
        }
        if (left) left->next = right_s;
        if (!head) return right;
        return head;
    }
	//----------------------------------------------//
    ListNode *partition(ListNode *head, int x) {
			if (!head)
				return NULL;

			ListNode *cur = NULL;
			ListNode *left = NULL;
			ListNode *l_tail = NULL;
			ListNode *right = NULL;
			ListNode *r_tail = NULL;

			cur = head;
			while(cur) {
			//cout << "val " << cur->val << endl;
				if (cur->val < x) {
					if (!left) {
						left = cur;
						l_tail = left;
					} else {
						l_tail->next = cur;
						l_tail = l_tail->next;
					}
				} else {
					if (!right) {
						right = cur;
						r_tail = right;
					} else {
						r_tail->next = cur;
						r_tail = r_tail->next;
					}
				}
				cur = cur->next;
			}
			if (r_tail)			
				r_tail->next = NULL;
			if (l_tail)			
				l_tail->next = NULL;
//			cout << "here111\n";
			if (left)
				l_tail->next = right;
			else
				return right;
	//		cout << "here\n";
			return left;
    }
};

int main(int argc, char **argv) {
	ListNode *head = new ListNode(1);
	/*ListNode *second = new ListNode(1);
	ListNode *third = new ListNode(3);
	head->next = second;
	second->next = third;*/
	Solution sol;
	head = sol.partition(head, 0);
	while(head) {
		cout << head->val << " ";
		head = head->next;
	}
	cout << endl;
	return 0;
}
