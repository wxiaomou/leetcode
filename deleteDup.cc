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
    ListNode *deleteDuplicates(ListNode *head) {
			if (!head)
				return NULL;

			if (!head->next)
				return head;

			ListNode *pre = head;
			ListNode *cur = head->next;

			while (cur) {
				if (pre->val == cur->val) {
					pre->next = cur->next;
					cur = cur->next;
				} else {
					pre = cur;
					cur = cur->next;
				}
			}

			return head;
    }
};

int main (int argc, char **argv) {
	return 0;
}
